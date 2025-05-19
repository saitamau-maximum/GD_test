# GD_test
---
# クローンの手順
・https://github.com/Tealands/GD_test　にアクセスする
・CodeからURLをコピーする
・git clone (URL) をVSCodeでクローンしたいディレクトリでターミナルに打ち込む
---
# issueからbranchを作る


//branch名はアルファベットで書くこと
---
# mergeを依頼する手順

 ターミナルで以下のように打ち込む
git add .
git commit -m "メッセージ"　//メッセージは日本語を含めてよい
git push
・https://github.com/Tealands/GD_test
でpullrequestを作成する

---
#　以下のブランチに関するコード一覧
git branch -a <!-- ブランチを確認 -->
git branch -d branchname<!-- ブランチを削除 -->
git checkout -b branchname<!-- ブランチを作成 -->
git checkout branchname<!-- ブランチを変更 -->
git pull origin main<!-- リモートリポジトリのmainをプル -->
---