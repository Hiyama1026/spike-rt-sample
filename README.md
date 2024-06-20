# Spike-rt sample

## 概要
- spike-rtの各種サンプル，及びRasPike互換モジュール（[raspike_spikert](./raspike_spikert/)）
    - spike-rt：https://github.com/spike-rt/spike-rt


## 動作確認済みの環境
- ホストPC環境
    - WSL2またはUbuntu22.04
- [spike-rt v0.2.0](https://github.com/spike-rt/spike-rt/tree/v0.2.0)

## アプリケーションの使用方法

### spike-rtのインストール，及びカーネルライブラリ等の作成
```
git clone -b v0.2.0 https://github.com/spike-rt/spike-rt.git
cd spike-rt
git submodule update --init ./external/ 
./scripts/build-test.sh
```

### 本サンプルアプリケーションのインストール・ビルド
```
cd spike-rt
git clone https://github.com/Hiyama1026/spike-rt-sample.git
cd spike-rt-sample/[PATH_TO_PROJECT]
make
```

### Hubへのアプリケーションの書き込み
- WSL2を使用する場合
    - 下記を実行して書き込み
    ```
    cd spike-rt
    curl -OL  https://dfu-util.sourceforge.net/releases/dfu-util-0.11-binaries.tar.xz
    tar Jxfv dfu-util-0.11-binaries.tar.xz
    cd spike-rt-sample/[PATH_TO_PROJECT]
    make deploy-win     # HubをDFUモードにしてから実行
    ```

- Ubuntuを使用する場合
    - pyusbのインストールが未実施の場合はspike-rt公式ドキュメントを参照
        - spike-rtドキュメント
            - [https://github.com/spike-rt/spike-rt/blob/main/docs/ja/Env.md](https://github.com/spike-rt/spike-rt/blob/main/docs/ja/Env.md#%E6%9B%B8%E3%81%8D%E8%BE%BC%E3%81%BF%E7%92%B0%E5%A2%83%E3%81%AE%E6%A7%8B%E7%AF%89)
        - venvを使用する必要が無い場合は下記コマンドでも可
        ```
        sudo apt install python3-pip    # pipのインストールが未実施の場合のみ実行
        sudo pip3 install pyusb
        ```
    - 下記を実行して書き込み
    ```
    cd spike-rt-sample/[PATH_TO_PROJECT]
    make deploy-lin     # パスワードの入力を求められる場合あり
    ```

### アプリケーションのビルドから書き込みまでの実行例
- API-sample/bluetooth1をビルドして書き込み
```
cd spike-rt/spike-rt-sample/API-sample/bluetooth1
make
# HubをDFUモードにする
make deploy-win     # WSL2上で実行する場合
make deploy-lin     # Ubuntu上で実行する場合
```

### HubをDFUモードにする方法
- HubのBluetoothボタンを押したまま，USBケーブルでHubとPCを接続する
- Bluetoothボタンが虹色に光るようになるまでボタンを押し続ける


## シリアル通信について
- 有線のシリアル通信はHub上部のUSBポートから行う
    - SPIKE-Prime付属のUSBケーブル等でPCと接続する
### Windows上でログを出す場合
- Tera Term等を使用
    - 参考：https://forest.watch.impress.co.jp/library/software/utf8teraterm/
- ボーレートは115200

### Ubuntu上でログを出す場合
- minicom等を使用
- インストール
    ```
    sudo apt update
    sudo apt install minicom
    ```
- 実行（デバイス名は適宜変更）
    ```
    sudo minicom -D /dev/ttyACM0
    ```
### Bluetoothを使用する場合
- Pybricksのコンソールを使用する
    - Chromeを使用すること
    - Pybricks：https://pybricks.com/
- Bluetooth接続をするHubの電源を入れる
    - syslogをBluetooth経由で出力するサンプル：[API-sample/syslog_bluetooth](./API-sample/README.md/#syslog_bluetoothc)
    - シリアルインターフェスドライバを使用したサンプル：[API-sample/bluetooth1](./API-sample/bluetooth1/)
- Start coding with Blocks & Pyhtonからコンソールを開く
- コンソール左上のBluetoothボタンからデバイスを選択する
    - 「不明またはサポートされていないデバイス」と表示される場合があるが，選択して接続する

## API 
- spike-rt API
    - [APIドキュメント](https://spike-rt.github.io/spike-rt/ja/html/modules.html)を参照。
