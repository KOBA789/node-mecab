#include <v8.h>
#include <mecab.h>

using namespace v8;

MeCab::Tagger *tagger;

Handle<Value> Parse(const Arguments& args) {
	HandleScope scope;
	if (args.Length() != 1 || !args[0]->IsString()) {
    	// 引数がおかしい場合は例外を投げる
		return ThrowException(Exception::Error(String::New("Bad argument.")));
	}
	
	String::Utf8Value input(args[0]->ToString());
	
	const char *result = tagger->parse(*input);	

	return String::New(result);
}

extern "C" void init(Handle<Object> target) {
	HandleScope scope;
	
	tagger = MeCab::createTagger("");
	
	target->Set(String::New("parse"), FunctionTemplate::New(Parse)->GetFunction());
}
