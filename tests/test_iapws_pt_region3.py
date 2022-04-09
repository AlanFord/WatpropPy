# test WatpropPy at IAPWS statepoints as a function of P,T
import pytest

import WatpropPy

pytestmark = pytest.mark.basic

tol = 1e-7
#       pressure,     deg-K,   spVol,           enthalpy,        entropy,         speedOfSound,    heatCap
data = [
	[0.255837018E+02, 650.0, 0.200000000E-02, 0.186343019E+04, 0.405427273E+01, 0.502005554E+03, 0.138935717E+02],
	[0.222930643E+02, 650.0, 0.500000000E-02, 0.237512401E+04, 0.485438792E+01, 0.383444594E+03, 0.446579342E+02],
	[0.783095639E+02, 750.0, 0.200000000E-02, 0.225868845E+04, 0.446971906E+01, 0.760696041E+03, 0.634165359E+01]]

#=============================================================
class TestEnthalpy():
	def test_Case0(self):
		index = 0
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][3]
		assert WatpropPy.H_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case1(self):
		index = 1
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][3]
		assert WatpropPy.H_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case2(self):
		index = 2
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][3]
		assert WatpropPy.H_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

class TestSpecificVolume():
	def test_Case0(self):
		index = 0
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][2]
		assert WatpropPy.V_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case1(self):
		index = 1
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][2]
		assert WatpropPy.V_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case2(self):
		index = 2
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][2]
		assert WatpropPy.V_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

class TestEntropy():
	def test_Case0(self):
		index = 0
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][4]
		assert WatpropPy.S_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case1(self):
		index = 1
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][4]
		assert WatpropPy.S_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case2(self):
		index = 2
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][4]
		assert WatpropPy.S_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

class TestSound():
	def test_Case0(self):
		index = 0
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][5]
		assert WatpropPy.W_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case1(self):
		index = 1
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][5]
		assert WatpropPy.W_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case2(self):
		index = 2
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][5]
		assert WatpropPy.W_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

class TestCp():
	def test_Case0(self):
		index = 0
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][6]
		assert WatpropPy.CP_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case1(self):
		index = 1
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][6]
		assert WatpropPy.CP_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case2(self):
		index = 2
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][6]
		assert WatpropPy.CP_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)



