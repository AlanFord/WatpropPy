# test WatpropPy at IAPWS statepoints as a function of P,T
import pytest

import WatpropPy

pytestmark = pytest.mark.basic

tol = 1e-7
data = [
	[3.0,      300.0, 0.100215168E-02, 0.115331273E+03, 0.392294792E+00, 0.150773921E+04, 0.417301218E+01],
	[80.0,     300.0, 0.971180894E-03, 0.184142828E+03, 0.368563852E+00, 0.163469054E+04, 0.401008987E+01],
	[3.0,      500.0, 0.120241800E-02, 0.975542239E+03, 0.258041912E+01, 0.124071337E+04, 0.465580682E+01],
	[0.0035,   300.0, 0.394913866E+02, 0.254991145E+04, 0.852238967E+01, 0.427920172E+03, 0.191300162E+01],
	[0.0035,   700.0, 0.923015898E+02, 0.333568375E+04, 0.101749996E+02, 0.644289068E+03, 0.208141274E+01],
	[30.0,     700.0, 0.542946619E-02, 0.263149474E+04, 0.517540298E+01, 0.480386523E+03, 0.103505092E+02],
	[0.5,     1500.0, 0.138455090E+01, 0.521976855E+04, 0.965408875E+01, 0.917068690E+03, 0.261609445E+01],
	[30.0,    1500.0, 0.230761299E-01, 0.516723514E+04, 0.772970133E+01, 0.928548002E+03, 0.272724317E+01],
	[30.0,    2000.0, 0.311385219E-01, 0.657122604E+04, 0.853640523E+01, 0.106736948E+04, 0.288569882E+01],
	[22.064, 647.096, 0.310559006E-02, -1,              -1,              -1,              -1]]

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

	def test_Case3(self):
		index = 3
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][3]
		assert WatpropPy.H_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case4(self):
		index = 4
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][3]
		assert WatpropPy.H_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case5(self):
		index = 5
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][3]
		assert WatpropPy.H_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case6(self):
		index = 6
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][3]
		assert WatpropPy.H_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case7(self):
		index = 7
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][3]
		assert WatpropPy.H_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case8(self):
		index = 8
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

	def test_Case3(self):
		index = 3
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][2]
		assert WatpropPy.V_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case4(self):
		index = 4
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][2]
		assert WatpropPy.V_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case5(self):
		index = 5
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][2]
		assert WatpropPy.V_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case6(self):
		index = 6
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][2]
		assert WatpropPy.V_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case7(self):
		index = 7
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][2]
		assert WatpropPy.V_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case8(self):
		index = 8
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][2]
		assert WatpropPy.V_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case9(self):
		index = 9
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

	def test_Case3(self):
		index = 3
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][4]
		assert WatpropPy.S_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case4(self):
		index = 4
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][4]
		assert WatpropPy.S_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case5(self):
		index = 5
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][4]
		assert WatpropPy.S_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case6(self):
		index = 6
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][4]
		assert WatpropPy.S_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case7(self):
		index = 7
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][4]
		assert WatpropPy.S_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case8(self):
		index = 8
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

	def test_Case3(self):
		index = 3
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][5]
		assert WatpropPy.W_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case4(self):
		index = 4
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][5]
		assert WatpropPy.W_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case5(self):
		index = 5
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][5]
		assert WatpropPy.W_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case6(self):
		index = 6
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][5]
		assert WatpropPy.W_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case7(self):
		index = 7
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][5]
		assert WatpropPy.W_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case8(self):
		index = 8
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

	def test_Case3(self):
		index = 3
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][6]
		assert WatpropPy.CP_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case4(self):
		index = 4
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][6]
		assert WatpropPy.CP_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case5(self):
		index = 5
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][6]
		assert WatpropPy.CP_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case6(self):
		index = 6
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][6]
		assert WatpropPy.CP_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case7(self):
		index = 7
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][6]
		assert WatpropPy.CP_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)

	def test_Case8(self):
		index = 8
		pressure =    data[index][0]
		temperature = data[index][1]-273.15
		answer =      data[index][6]
		assert WatpropPy.CP_PT(pressure,temperature,WatpropPy.Units.SI, WatpropPy.Units.SI) == pytest.approx(answer,rel=tol)



