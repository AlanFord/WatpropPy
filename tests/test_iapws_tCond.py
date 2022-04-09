# test WatpropPy at IAPWS statepoints as a function of P,T
import pytest

import WatpropPy

pytestmark = pytest.mark.basic

tol = 1e-3
#   degK,  pressure, thermal cond
data = [
	[25,    0.1,   607.5],
	[200,   0.1,   33.4 ],
	[800,   0.1,   107.7],
	[25,    100.0, 656.4],
	[200,   100.0, 733.2],
	[800,   100.0, 213.2]]

#=============================================================
class TestConductivity():
	def test_Case0(self):
		index = 0
		pressure =    data[index][1]
		temperature = data[index][0]
		answer =      data[index][2]
		assert WatpropPy.K_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case1(self):
		index = 1
		pressure =    data[index][1]
		temperature = data[index][0]
		answer =      data[index][2]
		assert WatpropPy.K_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case2(self):
		index = 2
		pressure =    data[index][1]
		temperature = data[index][0]
		answer =      data[index][2]
		assert WatpropPy.K_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case3(self):
		index = 3
		pressure =    data[index][1]
		temperature = data[index][0]
		answer =      data[index][2]
		assert WatpropPy.K_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case4(self):
		index = 4
		pressure =    data[index][1]
		temperature = data[index][0]
		answer =      data[index][2]
		assert WatpropPy.K_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case5(self):
		index = 5
		pressure =    data[index][1]
		temperature = data[index][0]
		answer =      data[index][2]
		assert WatpropPy.K_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

