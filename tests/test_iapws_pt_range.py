# test WatpropPy at IAPWS statepoints as a function of P,T
import pytest

import WatpropPy

pytestmark = pytest.mark.basic

tol = 1e-7
si = WatpropPy.Units.SI
english = WatpropPy.Units.ENGLISH

#=============================================================

class TestEnthalpy():
	def test_Case0(self):
		temperature = 0
		pressure =    100
		# any exception raised will fail the test
		WatpropPy.H_PT(pressure,temperature,si, si)

	def test_Case1(self):
		temperature = 0
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.H_PT(pressure,temperature,si,si)

	def test_Case2(self):
		temperature = 800
		pressure =    100
		# any exception raised will fail the test
		WatpropPy.H_PT(pressure,temperature,si,si)

	def test_Case3(self):
		temperature = 800
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.H_PT(pressure,temperature,si,si)

	def test_Case4(self):
		temperature = 2000
		pressure =    50
		# any exception raised will fail the test
		WatpropPy.H_PT(pressure,temperature,si,si)

	def test_Case5(self):
		temperature = 2000
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.H_PT(pressure,temperature,si,si)

	def test_Case6(self):
		temperature = 647.096
		pressure =    22.064
		# any exception raised will fail the test
		WatpropPy.H_PT(pressure,temperature,si,si)

	def test_Case7(self):
		temperature = 0
		pressure =    100.1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.H_PT(pressure,temperature,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

class TestSpecificVolume():
	def test_Case0(self):
		temperature = 0
		pressure =    100
		# any exception raised will fail the test
		WatpropPy.V_PT(pressure,temperature,si, si)


class TestEntropy():
	def test_Case0(self):
		temperature = 0
		pressure =    100
		# any exception raised will fail the test
		WatpropPy.S_PT(pressure,temperature,si, si)


class TestSound():
	def test_Case0(self):
		temperature = 0
		pressure =    100
		# any exception raised will fail the test
		WatpropPy.W_PT(pressure,temperature,si, si)

class TestCp():
	def test_Case0(self):
		temperature = 0
		pressure =    100
		# any exception raised will fail the test
		WatpropPy.CP_PT(pressure,temperature,si, si)



