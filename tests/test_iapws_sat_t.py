# test WatpropPy at IAPWS statepoints as a function of saturation temperature
import pytest

import WatpropPy

pytestmark = pytest.mark.basic

si = WatpropPy.units.si
english = WatpropPy.units.english

tol = 1e-7
data = [
	[623.15,  0.165291643E+02],
	[300.0,   0.353658941E-02],
	[500.0,   0.263889776E+01],
	[600.0,   0.123443146E+02],
	[647.096, 0.220640000E+02]]

#=============================================================
class TestEnthalpy():
	def test_Case0(self):
		index = 0
		temperature = data[index][0]-273.15
		answer =      data[index][1]
		assert WatpropPy.p_t(temperature,si, si) == pytest.approx(answer,rel=tol)

	def test_Case1(self):
		index = 1
		temperature = data[index][0]-273.15
		answer =      data[index][1]
		assert WatpropPy.p_t(temperature,si, si) == pytest.approx(answer,rel=tol)

	def test_Case2(self):
		index = 2
		temperature = data[index][0]-273.15
		answer =      data[index][1]
		assert WatpropPy.p_t(temperature,si, si) == pytest.approx(answer,rel=tol)

	def test_Case3(self):
		index = 3
		temperature = data[index][0]-273.15
		answer =      data[index][1]
		assert WatpropPy.p_t(temperature,si, si) == pytest.approx(answer,rel=tol)

	def test_Case4(self):
		index = 4
		temperature = data[index][0]-273.15
		answer =      data[index][1]
		assert WatpropPy.p_t(temperature,si, si) == pytest.approx(answer,rel=tol)



