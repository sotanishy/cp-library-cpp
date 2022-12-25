# ICPC 用ドキュメント

[横浜国立大学競技プログラミング部の ICPC ライブラリ](https://github.com/YNUCPC/ynu-icpc-library) の tex テンプレートを使用している．

## ファイル

- `preamble.tex`
    - 必要なパッケージのインポートや見た目の設定
- `main.tex`
    - セクションの定義
- `{section name}.tex`
    - 各セクション
- `file_list.py`
    - ドキュメントに載せるセクションとファイルのリスト
- `generate.py`
    - リストのファイルから，各セクションのファイルを自動生成するスクリプト
- `template`
    - `generate.py` で使うための雛形

## 作成方法

1. `file_list.py` に，ドキュメントに載せるセクションとファイルをリストする．
2. `generate.py` を実行して，tex ファイルを自動生成する
3. (ドキュメントを手動で添削する)
4. `latexmk main.tex` を実行して `main.pdf` を生成する