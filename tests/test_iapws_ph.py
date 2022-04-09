# test WatpropPy at IAPWS statepoints as a function of P,H
import pytest

import WatpropPy

pytestmark = pytest.mark.basic

tol = 1e-7
data = [
	[3.0,              300.0, 0.100215168E-02, 0.392294792E+00],
	[80.0,             300.0, 0.971180894E-03, 0.368563852E+00],
	[3.0,              500.0, 0.120241800E-02, 0.258041912E+01],
	[0.0035,           300.0, 0.394913866E+02, 0.852238967E+01],
	[0.0035,           700.0, 0.923015898E+02, 0.101749996E+02],
	[30.0,             700.0, 0.542946619E-02, 0.517540298E+01],
	[0.5,             1500.0, 0.138455090E+01, 0.965408875E+01],
	[30.0,            1500.0, 0.230761299E-01, 0.772970133E+01],
	[30.0,            2000.0, 0.311385219E-01, 0.853640523E+01],
	[0.255837018E+02,  650.0, 0.200000000E-02, 0.405427273E+01],
	[0.222930643E+02,  650.0, 0.500000000E-02, 0.485438792E+01],
	[0.783095639E+02,  750.0, 0.200000000E-02, 0.446971906E+01]]

#=============================================================
class TestTemperature():
	def test_Case0(self):
		index = 0
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      inTemp
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case1(self):
		index = 1
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      inTemp
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case2(self):
		index = 2
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      inTemp
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case3(self):
		index = 3
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      inTemp
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case4(self):
		index = 4
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      inTemp
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case5(self):
		index = 5
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      inTemp
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case6(self):
		index = 6
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      inTemp
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case7(self):
		index = 7
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      inTemp
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case8(self):
		index = 8
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      inTemp
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case9(self):
		index = 9
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      inTemp
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case10(self):
		index = 10
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      inTemp
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case11(self):
		index = 11
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      inTemp
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

class TestSpecificVolume():
	def test_Case0(self):
		index = 0
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][2]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case1(self):
		index = 1
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][2]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case2(self):
		index = 2
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][2]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case3(self):
		index = 3
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][2]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case4(self):
		index = 4
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][2]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case5(self):
		index = 5
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][2]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case6(self):
		index = 6
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][2]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case7(self):
		index = 7
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][2]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case8(self):
		index = 8
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][2]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case9(self):
		index = 9
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][2]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case10(self):
		index = 10
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][2]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case11(self):
		index = 11
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][2]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

class TestEntropy():
	def test_Case0(self):
		index = 0
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][3]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case1(self):
		index = 1
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][3]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case2(self):
		index = 2
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][3]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case3(self):
		index = 3
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][3]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case4(self):
		index = 4
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][3]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case5(self):
		index = 5
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][3]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case6(self):
		index = 6
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][3]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case7(self):
		index = 7
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][3]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case8(self):
		index = 8
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][3]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case9(self):
		index = 9
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][3]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case10(self):
		index = 10
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][3]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case11(self):
		index = 11
		pressure =    data[index][0]
		inTemp = data[index][1]-273.15
		enthalpy = WatpropPy.H_PT(pressure,inTemp,WatpropPy.Units.SI, WatpropPy.Units.SI)
		answer =      data[index][3]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)
