GameDataControl

used for data interaction between excel sheet and JSON files

initial commit with two directories

datagenerate serves as intermediate file from data type definition to xlsx files

datadefine		: JSON definition files used for defining data forms
datagenerate	: excel files used for generating resulting JSON files used in game

ProtobufControl/example/cpp [CPP Protobuf  작업 루트]

명령어 : 'protoc -I=./protocol/source --cpp_out=./protocol/dest ./protocol/source/$1'

