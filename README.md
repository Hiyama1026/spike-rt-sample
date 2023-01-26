# Spike-rt sample

## アプリケーションのビルド方法

### カーネルライブラリ等を作成．
```
git clone https://github.com/spike-rt/spike-rt.git
cd spike-rt
git submodule update --init ./external/ 
./scripts/build-test.sh
```

### アプリケーションのビルド
```
git clone https://github.com/Hiyama1026/spike-rt-sample.git
cd spike-rt-sample/$appdir/$appdir
make
```

## 注意事項
- このサンプルは[spike-rt](https://github.com/spike-rt/spike-rt)の直下に展開すると実行することができます。
- 1回目のビルド時にエラーが出るかもしれません。その場合はもう一度ビルドをしてみてください。2回目のビルドで問題なく実行できるようになります。

## API 
- Spike API
    - [APIドキュメント](https://spike-rt.github.io/spike-rt/ja/html/modules.html)を参照。


