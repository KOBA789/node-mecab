var MeCab = require('./build/default/mecab');

//そのまま使えば普通の出力だよん
var nomal = new MeCab.Tagger();
console.log(nomal.parse("すもももももももものうち"));

//コンストラクタに引数を渡せばわかち書きとかになるよん
var wakati = new MeCab.Tagger("-O wakati");
console.log(wakati.parse("すもももももももものうち"));
