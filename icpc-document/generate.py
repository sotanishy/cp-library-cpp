import os
from collections import namedtuple
from jinja2 import Environment, FileSystemLoader

from file_list import paths

Section = namedtuple("Section", ["title", "files"])
File = namedtuple("File", ["title", "doc", "src"])
skip_sections = ["convolution", "data-structure", "flow", "geometry", "graph", "misc", "sat", "string", "tree"]
# skip_sections = ["convolution", "flow", "geometry",
#                  "graph", "math", "misc", "string", "tree"]


def fix_string(s):
    return s.replace("_", "\\_")


def parse_file(src_path):
    with open(src_path, encoding="utf-8") as f:
        lines = []
        for line in f.readlines():
            # remove include and pragma
            if line.strip().startswith("#pragma") or line.strip().startswith("#include <"):
                continue
            lines.append(line)
        # remove empty lines at the beginning and the end of the document
        while lines and lines[0].strip() == "":
            lines.pop(0)
        while lines and lines[-1].strip() == "":
            lines.pop()
        src = "".join(lines)

    path = src_path.split("/")
    path.insert(1, "docs")

    title = fix_string(path[-1])

    path[-1] = ".".join(path[-1].split(".")[:-1] + ["md"])
    md_path = "/".join(path)

    if not os.path.isfile(md_path):
        return File(title, "", src)

    with open(md_path, encoding="utf-8") as f:
        lines = list(map(lambda line: line.rstrip(), f.readlines()))

        # parse front matter
        k = 0
        if lines[0] == "---":
            k += 1
            while lines[k] != "---":
                if lines[k].startswith("title"):
                    title = fix_string(lines[k][7:])
                k += 1
            k += 1

        sections = {}
        cur_section = None
        for line in lines[k:]:
            if line.startswith("##"):
                cur_section = line[3:]
                sections[cur_section] = []
                # change heading to bold
                line = f"**{cur_section}**"
            if cur_section is not None:
                sections[cur_section].append(line)

    remove_sections = ["Reference"]
    for sec in remove_sections:
        if sec in sections:
            del sections[sec]

    doc = []
    for sec, lines in sections.items():
        doc += lines
    doc = fix_string("\n".join(doc))

    return File(title, doc, src)


def generate_tex():
    env = Environment(loader=FileSystemLoader("./template"))

    # main file
    template = env.get_template("main.tex")
    out = template.render({"sections": paths.keys()})
    with open("main.tex", "w", encoding="utf-8") as f:
        f.write(out)

    # section
    for sec, path_list in paths.items():
        if sec in skip_sections:
            continue
        files = []
        for path in path_list:
            files.append(parse_file(path))
        section = Section(title=sec, files=files)
        template = env.get_template("section.tex")
        out = template.render({"section": section})
        with open(f"{sec}.tex", "w", encoding="utf-8") as f:
            f.write(out)


if __name__ == "__main__":
    generate_tex()
