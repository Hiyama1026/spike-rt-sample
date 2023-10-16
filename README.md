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

## 動作確認済みのspike-rtバージョン(2023/07/04)
- raspike_spikrtのみ，新しいspike-rtのバージョンに対応しました．
    - コミットID：f6724115b0ef8c8367a760eaec2840089e6b4e55
    - [Git Hub](https://github.com/spike-rt/spike-rt/tree/f6724115b0ef8c8367a760eaec2840089e6b4e55)

- raspike_spikert以外のプログラム
    - コミットID：e663a2d2ba16422df34efd9ad36737ec75ad4d0d

- raspike_spikert以外のプログラムもアプリのMakefileを以下のように変更する事により，raspike_spikrtの動作確認済みバージョンと同じバージョンのspike-rtでビルドできるはずです（未確認）．
```
<変更前>
ALL_LIBS = -lkernel $(LIBS)
<変更後>
ALL_LIBS = -lkernel $(LIBS) -lkernel
```
## API 
- Spike API
    - [APIドキュメント](https://spike-rt.github.io/spike-rt/ja/html/modules.html)を参照。


