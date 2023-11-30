# Spike-rt sample

## アプリケーションの使用方法

### spike-rtのインストール，及びカーネルライブラリ等の作成．
```
git clone https://github.com/spike-rt/spike-rt.git
cd spike-rt
git submodule update --init ./external/ 
./scripts/build-test.sh
```

### 本サンプルアプリケーションのインストール・ビルド
```
cd spike-rt
git clone https://github.com/Hiyama1026/spike-rt-sample.git
cd spike-rt-sample/[app_dir]/[app_name_dir]
make asp.bin
```

## 注意事項
- このサンプルは[spike-rt](https://github.com/spike-rt/spike-rt)の直下に展開すると実行することができます。
- 1回目のビルド時にエラーが出るかもしれません。その場合はもう一度ビルドをしてみてください。2回目のビルドで問題なく実行できるようになります。

## 動作確認済みバージョン
- [spike-rt](https://github.com/spike-rt/spike-rt/tree/567c6dea68581633060245e149f0bc2be5977ed1)
    - コミットID：567c6dea68581633060245e149f0bc2be5977ed1

## API 
- spike-rt API
    - [APIドキュメント](https://spike-rt.github.io/spike-rt/ja/html/modules.html)を参照。
