#include "RespecterEcheance.h"

RespecterEcheance::RespecterEcheance(system_clock::duration dt) {
	echeance = base + dt;
}
bool RespecterEcheance::operator()() const {
	return system_clock::now() < echeance;
}
