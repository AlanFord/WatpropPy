# test WatpropPy at IAPWS statepoints as a function of P,T
import pytest

import WatpropPy

pytestmark = pytest.mark.basic

tol = 1e-3
#   degK,  pressure, visc
data = [
	[25,    0.1,   890.1],
	[200,   0.1,   16.18],
	[800,   0.1,   40.38],
	[25,    100.0, 889.7],
	[200,   100.0, 155.9],
	[800,   100.0, 52.10]]

#=============================================================
class TestViscosity():
	def test_Case0(self):
		index = 0
		pressure =    data[index][1]
		temperature = data[index][0]
		answer =      data[index][2]
		assert WatpropPy.VIS_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case1(self):
		index = 1
		pressure =    data[index][1]
		temperature = data[index][0]
		answer =      data[index][2]
		assert WatpropPy.VIS_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case2(self):
		index = 2
		pressure =    data[index][1]
		temperature = data[index][0]
		answer =      data[index][2]
		assert WatpropPy.VIS_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case3(self):
		index = 3
		pressure =    data[index][1]
		temperature = data[index][0]
		answer =      data[index][2]
		assert WatpropPy.VIS_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case4(self):
		index = 4
		pressure =    data[index][1]
		temperature = data[index][0]
		answer =      data[index][2]
		assert WatpropPy.VIS_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case5(self):
		index = 5
		pressure =    data[index][1]
		temperature = data[index][0]
		answer =      data[index][2]
		assert WatpropPy.VIS_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

