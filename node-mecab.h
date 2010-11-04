#ifndef _ECHO_
#define _ECHO_

#include <node.h>
#include <v8.h>
#include <mecab.h>

using namespace v8; 
using namespace node;

// node.js が用意しているObjectWrapを継承することで自作のクラスもGC対象にする
class Tagger : ObjectWrap { 
    public:
        // node.jsにメソッドを登録するためにstaticにしてる
        // インスタンスを作る関数はNewにするのが通例っぽい
        static Handle<Value> New(const Arguments& args);
        static Handle<Value> Parse(const Arguments& args);
        Tagger(){}; 
        ~Tagger();
	private:
        MeCab::Tagger *tagger;
};

static void AddonInitialize( Handle<Object> target );
#endif
