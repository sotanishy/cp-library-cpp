---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import os\nfrom collections import namedtuple\nfrom jinja2 import Environment,\
    \ FileSystemLoader\n\nfrom file_list import paths\n\nSection = namedtuple(\"Section\"\
    , [\"title\", \"files\"])\nFile = namedtuple(\"File\", [\"title\", \"doc\", \"\
    src\"])\nskip_sections = [\"convolution\", \"flow\", \"geometry\", \"graph\",\
    \ \"math\", \"misc\", \"string\", \"tree\"]\n\n\ndef fix_string(s):\n    return\
    \ s.replace(\"_\", \"\\\\_\")\n\n\ndef parse_file(src_path):\n    with open(src_path,\
    \ encoding=\"utf-8\") as f:\n        src = \"\".join(f.readlines())\n\n    path\
    \ = src_path.split(\"/\")\n    path.insert(1, \"docs\")\n\n    title = fix_string(path[-1])\n\
    \n    path[-1] = \".\".join(path[-1].split(\".\")[:-1] + [\"md\"])\n    md_path\
    \ = \"/\".join(path)\n\n    if not os.path.isfile(md_path):\n        return File(title,\
    \ \"\", src)\n\n    with open(md_path, encoding=\"utf-8\") as f:\n        lines\
    \ = list(map(lambda line: line.rstrip(), f.readlines()))\n\n        # parse front\
    \ matter\n        k = 0\n        if lines[0] == \"---\":\n            k += 1\n\
    \            while lines[k] != \"---\":\n                if lines[k].startswith(\"\
    title\"):\n                    title = fix_string(lines[k][7:])\n            \
    \    k += 1\n            k += 1\n\n        sections = {}\n        cur_section\
    \ = None\n        for line in lines[k:]:\n            if line.startswith(\"##\"\
    ):\n                cur_section = line[3:]\n                sections[cur_section]\
    \ = []\n                # change heading to bold\n                line = f\"**{cur_section}**\"\
    \n            if cur_section is not None:\n                sections[cur_section].append(line)\n\
    \n    remove_sections = [\"Reference\"]\n    for sec in remove_sections:\n   \
    \     if sec in sections:\n            del sections[sec]\n\n    doc = []\n   \
    \ for sec, lines in sections.items():\n        doc += lines\n    doc = fix_string(\"\
    \\n\".join(doc))\n\n    return File(title, doc, src)\n\n\ndef generate_tex():\n\
    \    env = Environment(loader=FileSystemLoader(\"./template\"))\n\n    # main\
    \ file\n    template = env.get_template(\"main.tex\")\n    out = template.render({\"\
    sections\": paths.keys()})\n    with open(\"main.tex\", \"w\", encoding=\"utf-8\"\
    ) as f:\n        f.write(out)\n\n    # section\n    for sec, path_list in paths.items():\n\
    \        if sec in skip_sections:\n            continue\n        files = []\n\
    \        for path in path_list:\n            files.append(parse_file(path))\n\
    \        section = Section(title=sec, files=files)\n        template = env.get_template(\"\
    section.tex\")\n        out = template.render({\"section\": section})\n      \
    \  with open(f\"{sec}.tex\", \"w\", encoding=\"utf-8\") as f:\n            f.write(out)\n\
    \n\nif __name__ == \"__main__\":\n    generate_tex()"
  dependsOn: []
  isVerificationFile: false
  path: icpc-document/generate.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc-document/generate.py
layout: document
redirect_from:
- /library/icpc-document/generate.py
- /library/icpc-document/generate.py.html
title: icpc-document/generate.py
---
