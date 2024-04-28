#include "Calculation.h"
#include<Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

static const int kColumWidth = 60;
static const int kRowHeight = 20;

Calculation::Calculation() {
	v1_ = { 1.0f,3.0f,-5.0f };
	v2_ = { 4.0f,-1.0f,2.0f };
	k_ = { 4.0f };
	resultAdd_ = {};
	resultSubtract_ = {};
	resultMultiply_ = {};
	resultDot_ = {};
	resultLength_ = {};
	resultNormalize_ = {};


}
