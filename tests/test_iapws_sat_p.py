# test WatpropPy at IAPWS statepoints as a function of saturation pressure
import pytest

import WatpropPy

pytestmark = pytest.mark.basic

tol = 1e-7
data = [
	[0.1,    0.372755919E+03],
	[1.0,    0.453035632E+03],
	[10.0,   0.584149488E+03],
	[22.064, 0.647096000E+03]]

#=============================================================
class TestEnthalpy():
	def test_Case0(self):
		index = 0
		pressure = data[index][0]
		answer =      data[index][1]
		assert WatpropPy.T_P(pressure,WatpropPy.Units.SI, WatpropPy.Units.SI)+273.15 == pytest.approx(answer,rel=tol)

	def test_Case1(self):
		index = 1
		pressure = data[index][0]
		answer =      data[index][1]
		assert WatpropPy.T_P(pressure,WatpropPy.Units.SI, WatpropPy.Units.SI)+273.15 == pytest.approx(answer,rel=tol)

	def test_Case2(self):
		index = 2
		pressure = data[index][0]
		answer =      data[index][1]
		assert WatpropPy.T_P(pressure,WatpropPy.Units.SI, WatpropPy.Units.SI)+273.15 == pytest.approx(answer,rel=tol)

	def test_Case3(self):
		index = 3
		pressure = data[index][0]
		answer =      data[index][1]
		assert WatpropPy.T_P(pressure,WatpropPy.Units.SI, WatpropPy.Units.SI)+273.15 == pytest.approx(answer,rel=tol)



