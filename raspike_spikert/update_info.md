# アップデート情報

## 2023/07/04
raspike_spikertのみ変更<BR>
- raspike.cのミスを修正
    - 498行目あたり
```
if (data2 & 0x80U) {    //修正
    cmd = data2;
    num_fail++;
    continue;
}
```

- spike-rtのバージョンアップに追従
    - 動作確認済みのバージョン
        - コミット番号：f6724115b0ef8c8367a760eaec2840089e6b4e55
        - [Git Hub](https://github.com/spike-rt/spike-rt/tree/f6724115b0ef8c8367a760eaec2840089e6b4e55)

- Makefileを修正してビルドエラーをエスケープ
```
ALL_LIBS = -lkernel $(LIBS) -lkernel
```

- モーターの駆動APIを`pup_motor_set_power()`に変更
    - spike-rtにPWM値指定関数が追加されたため変更
    - 以前のバージョンではモーターの速度指令値に負の値を入れることができなかったが，可能になった