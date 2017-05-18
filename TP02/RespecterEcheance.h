#pragma once
#include <chrono>
using namespace std::chrono;
class RespecterEcheance {
	system_clock::time_point base = system_clock::now();
	system_clock::time_point echeance;
public:
	RespecterEcheance(system_clock::duration dt);
	bool operator()() const;
};