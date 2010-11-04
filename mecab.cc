#include <v8.h>
#include <node.h>
#include <iostream>
#include <mecab.h>
#include "node-mecab.h"

using namespace node;
using namespace v8; 
using namespace std;

Handle<Value> Tagger::New (const Arguments& args) {
	HandleScope scope;

	Tagger *p = new Tagger();
	p->Wrap(args.This());

	p->tagger = MeCab::createTagger((args.Length() >= 1 && args[0]->IsString()) ? *String::Utf8Value(args[0]->ToString()) : "");

	return args.This();
}

Handle<Value> Tagger::Parse (const Arguments& args) {
	HandleScope scope;
	if (args.Length() != 1 || !args[0]->IsString()) {
		return ThrowException(Exception::Error(String::New("Bad argument.")));
	}   

	Tagger *self = ObjectWrap::Unwrap<Tagger>(args.This());

	String::Utf8Value input(args[0]->ToString());

	const char *result = self->tagger->parse(*input);

	return String::New(result);
}

Tagger::~Tagger(){
	delete tagger;
}

void AddonInitialize (Handle<Object> target) {
	HandleScope scope;

	Local<FunctionTemplate> t = FunctionTemplate::New(Tagger::New);
	t->InstanceTemplate()->SetInternalFieldCount(1);
	t->SetClassName(String::NewSymbol("Tagger"));

	NODE_SET_PROTOTYPE_METHOD(t, "parse", Tagger::Parse);

	target->Set(String::New("Tagger"), t->GetFunction());
}

NODE_MODULE(mecab, AddonInitialize);
