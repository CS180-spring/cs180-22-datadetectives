#pragma once
#include<iostream>
#include<fstream>
#include <chrono>
using namespace std;

void BytesRead(ifstream file) {
	auto startTime = chrono::high_resolution_clock::now();
	file.seekg(0, ios::end);
	auto endTime = chrono::high_resolution_clock::now();
	auto readTime = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
	int fileBytes = file.tellg();
	cout << fileBytes << " Bytes Read.";
	cout << "File took " << readTime.count() << "ms to read.";
}