#include "stdafx.h"
#include <node.h>
#include "Wlan.cpp"

using namespace v8;


void Start(const FunctionCallbackInfo<Value>& args) {

  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);


  Local<Function> cb = Local<Function>::Cast(args[0]);
  const unsigned argc = 1;
  Local<Value> argv[argc] = { String::NewFromUtf8(isolate, "Stop callback") };
  cb->Call(isolate->GetCurrentContext()->Global(), argc, argv);
}




void Init(Handle<Object> exports, Handle<Object> module) {
  NODE_SET_METHOD(exports, "start", Start);
}

NODE_MODULE(addon, Init)