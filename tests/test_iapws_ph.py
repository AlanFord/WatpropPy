# test WatpropPy at IAPWS statepoints as a function of P,H
import pytest

import WatpropPy

pytestmark = pytest.mark.basic

tol = 1e-7
data = [

	[3.0,             0.115331273E+03, 299.99999999,  0.100215168E-02, 0.392294792E+00],
	[80.0,            0.184142828E+03, 300.00000007,  0.971180894E-03, 0.368563853E+00],
	[3.0,             0.975542239E+03, 499.99999998,  0.120241800E-02, 0.258041912E+01],
	[0.0035,          0.254991145E+04, 299.99999956,  0.394913866E+02, 0.852238966E+01],
	[0.0035,          0.333568375E+04, 699.99999821,  0.923015896E+02, 0.101749996E+02],
	[30.0,            0.263149474E+04, 699.99999953,  0.542946616E-02, 0.517540298E+01],
	[0.5,             0.521976855E+04, 1499.99999954, 0.138455090E+01, 0.965408875E+01],
	[30.0,            0.516723514E+04, 1499.99999997, 0.230761299E-01, 0.772970133E+01],
	[30.0,            0.657122604E+04, 2000.00000048, 0.311385219E-01, 0.853640523E+01],
	[0.255837018E+02, 0.186343019E+04, 650.00000001,  0.200000000E-02, 0.405427273E+01],
	[0.222930643E+02, 0.237512401E+04, 650.00000010,  0.500000003E-02, 0.485438793E+01],
	[0.783095639E+02, 0.225868845E+04, 750.00000072,  0.200000001E-02, 0.446971906E+01]]

#=============================================================
class TestTemperature():
	def test_Case0(self):
		index = 0
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][2]-273.15
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case1(self):
		index = 1
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][2]-273.15
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case2(self):
		index = 2
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][2]-273.15
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case3(self):
		index = 3
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][2]-273.15
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case4(self):
		index = 4
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][2]-273.15
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case5(self):
		index = 5
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][2]-273.15
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case6(self):
		index = 6
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][2]-273.15
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case7(self):
		index = 7
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][2]-273.15
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case8(self):
		index = 8
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][2]-273.15
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case9(self):
		index = 9
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][2]-273.15
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case10(self):
		index = 10
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][2]-273.15
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case11(self):
		index = 11
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][2]-273.15
		assert WatpropPy.T_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

class TestSpecificVolume():
	def test_Case0(self):
		index = 0
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][3]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case1(self):
		index = 1
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][3]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case2(self):
		index = 2
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][3]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case3(self):
		index = 3
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][3]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case4(self):
		index = 4
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][3]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case5(self):
		index = 5
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][3]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case6(self):
		index = 6
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][3]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case7(self):
		index = 7
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][3]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case8(self):
		index = 8
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][3]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case9(self):
		index = 9
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][3]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case10(self):
		index = 10
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][3]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case11(self):
		index = 11
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][3]
		assert WatpropPy.V_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

class TestEntropy():
	def test_Case0(self):
		index = 0
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][4]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case1(self):
		index = 1
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][4]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case2(self):
		index = 2
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][4]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case3(self):
		index = 3
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][4]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case4(self):
		index = 4
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][4]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case5(self):
		index = 5
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][4]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case6(self):
		index = 6
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][4]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case7(self):
		index = 7
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][4]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case8(self):
		index = 8
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][4]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case9(self):
		index = 9
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][4]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case10(self):
		index = 10
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][4]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case11(self):
		index = 11
		pressure =    data[index][0]
		enthalpy = data[index][1]
		answer =      data[index][4]
		assert WatpropPy.S_PH(pressure,enthalpy,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)
