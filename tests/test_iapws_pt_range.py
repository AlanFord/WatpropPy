# test WatpropPy at IAPWS statepoints as a function of P,T
import pytest

import WatpropPy

pytestmark = pytest.mark.basic

si = WatpropPy.units.si
english = WatpropPy.units.english

#=============================================================

class TestEnthalpy():
	def test_Case0(self):
		temperature = 0
		pressure =    100
		# any exception raised will fail the test
		WatpropPy.h_pt(pressure,temperature,si, si)

	def test_Case1(self):
		temperature = 0
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.h_pt(pressure,temperature,si,si)

	def test_Case2(self):
		temperature = 800
		pressure =    100
		# any exception raised will fail the test
		WatpropPy.h_pt(pressure,temperature,si,si)

	def test_Case3(self):
		temperature = 800
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.h_pt(pressure,temperature,si,si)

	def test_Case4(self):
		temperature = 2000
		pressure =    50
		# any exception raised will fail the test
		WatpropPy.h_pt(pressure,temperature,si,si)

	def test_Case5(self):
		temperature = 2000
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.h_pt(pressure,temperature,si,si)

	def test_Case6(self):
		temperature = 647.096
		pressure =    22.064
		# any exception raised will fail the test
		WatpropPy.h_pt(pressure,temperature,si,si)

	def test_Case7(self):
		temperature = 0
		pressure =    100.1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.h_pt(pressure,temperature,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

	def test_Case8(self):
		temperature = -1
		pressure =    1e-3
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.h_pt(pressure,temperature,si,si)
		assert "temperature out of bounds" in str(excinfo.value)

	def test_Case9(self):
		temperature = 800
		pressure =    100.1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.h_pt(pressure,temperature,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

	def test_Case10(self):
		temperature = 800
		pressure =    0
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.h_pt(pressure,temperature,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

	def test_Case11(self):
		temperature = 2000
		pressure =    50.01
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.h_pt(pressure,temperature,si,si)
		assert "pressure/temperature combination out of bounds" in str(excinfo.value)

	def test_Case12(self):
		temperature = 2000.1
		pressure =    1e-3
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.h_pt(pressure,temperature,si,si)
		assert "temperature out of bounds" in str(excinfo.value)

class TestSpecificVolume():
	def test_Case0(self):
		temperature = 0
		pressure =    100
		# any exception raised will fail the test
		WatpropPy.v_pt(pressure,temperature,si, si)

	def test_Case1(self):
		temperature = 0
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.v_pt(pressure,temperature,si,si)

	def test_Case2(self):
		temperature = 800
		pressure =    100
		# any exception raised will fail the test
		WatpropPy.v_pt(pressure,temperature,si,si)

	def test_Case3(self):
		temperature = 800
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.v_pt(pressure,temperature,si,si)

	def test_Case4(self):
		temperature = 2000
		pressure =    50
		# any exception raised will fail the test
		WatpropPy.v_pt(pressure,temperature,si,si)

	def test_Case5(self):
		temperature = 2000
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.v_pt(pressure,temperature,si,si)

	def test_Case6(self):
		temperature = 647.096
		pressure =    22.064
		# any exception raised will fail the test
		WatpropPy.v_pt(pressure,temperature,si,si)

	def test_Case7(self):
		temperature = 0
		pressure =    100.1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.v_pt(pressure,temperature,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

	def test_Case8(self):
		temperature = -1
		pressure =    1e-3
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.v_pt(pressure,temperature,si,si)
		assert "temperature out of bounds" in str(excinfo.value)

	def test_Case9(self):
		temperature = 800
		pressure =    100.1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.v_pt(pressure,temperature,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

	def test_Case10(self):
		temperature = 800
		pressure =    0
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.v_pt(pressure,temperature,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

	def test_Case11(self):
		temperature = 2000
		pressure =    50.01
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.v_pt(pressure,temperature,si,si)
		assert "pressure/temperature combination out of bounds" in str(excinfo.value)

	def test_Case12(self):
		temperature = 2000.1
		pressure =    1e-3
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.v_pt(pressure,temperature,si,si)
		assert "temperature out of bounds" in str(excinfo.value)


class TestEntropy():
	def test_Case0(self):
		temperature = 0
		pressure =    100
		# any exception raised will fail the test
		WatpropPy.s_pt(pressure,temperature,si, si)

	def test_Case1(self):
		temperature = 0
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.s_pt(pressure,temperature,si,si)

	def test_Case2(self):
		temperature = 800
		pressure =    100
		# any exception raised will fail the test
		WatpropPy.s_pt(pressure,temperature,si,si)

	def test_Case3(self):
		temperature = 800
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.s_pt(pressure,temperature,si,si)

	def test_Case4(self):
		temperature = 2000
		pressure =    50
		# any exception raised will fail the test
		WatpropPy.s_pt(pressure,temperature,si,si)

	def test_Case5(self):
		temperature = 2000
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.s_pt(pressure,temperature,si,si)

	def test_Case6(self):
		temperature = 647.096
		pressure =    22.064
		# any exception raised will fail the test
		WatpropPy.s_pt(pressure,temperature,si,si)

	def test_Case7(self):
		temperature = 0
		pressure =    100.1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.s_pt(pressure,temperature,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

	def test_Case8(self):
		temperature = -1
		pressure =    1e-3
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.s_pt(pressure,temperature,si,si)
		assert "temperature out of bounds" in str(excinfo.value)

	def test_Case9(self):
		temperature = 800
		pressure =    100.1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.s_pt(pressure,temperature,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

	def test_Case10(self):
		temperature = 800
		pressure =    0
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.s_pt(pressure,temperature,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

	def test_Case11(self):
		temperature = 2000
		pressure =    50.01
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.s_pt(pressure,temperature,si,si)
		assert "pressure/temperature combination out of bounds" in str(excinfo.value)

	def test_Case12(self):
		temperature = 2000.1
		pressure =    1e-3
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.s_pt(pressure,temperature,si,si)
		assert "temperature out of bounds" in str(excinfo.value)


class TestSound():
	def test_Case0(self):
		temperature = 0
		pressure =    100
		# any exception raised will fail the test
		WatpropPy.w_pt(pressure,temperature,si, si)

	def test_Case1(self):
		temperature = 0
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.w_pt(pressure,temperature,si,si)

	def test_Case2(self):
		temperature = 800
		pressure =    100
		# any exception raised will fail the test
		WatpropPy.w_pt(pressure,temperature,si,si)

	def test_Case3(self):
		temperature = 800
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.w_pt(pressure,temperature,si,si)

	def test_Case4(self):
		temperature = 2000
		pressure =    50
		# any exception raised will fail the test
		WatpropPy.w_pt(pressure,temperature,si,si)

	def test_Case5(self):
		temperature = 2000
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.w_pt(pressure,temperature,si,si)

	def test_Case6(self):
		temperature = 647.096
		pressure =    22.064
		# any exception raised will fail the test
		WatpropPy.w_pt(pressure,temperature,si,si)

	def test_Case7(self):
		temperature = 0
		pressure =    100.1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.w_pt(pressure,temperature,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

	def test_Case8(self):
		temperature = -1
		pressure =    1e-3
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.w_pt(pressure,temperature,si,si)
		assert "temperature out of bounds" in str(excinfo.value)

	def test_Case9(self):
		temperature = 800
		pressure =    100.1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.w_pt(pressure,temperature,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

	def test_Case10(self):
		temperature = 800
		pressure =    0
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.w_pt(pressure,temperature,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

	def test_Case11(self):
		temperature = 2000
		pressure =    50.01
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.w_pt(pressure,temperature,si,si)
		assert "pressure/temperature combination out of bounds" in str(excinfo.value)

	def test_Case12(self):
		temperature = 2000.1
		pressure =    1e-3
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.w_pt(pressure,temperature,si,si)
		assert "temperature out of bounds" in str(excinfo.value)

class TestCp():
	def test_Case0(self):
		temperature = 0
		pressure =    100
		# any exception raised will fail the test
		WatpropPy.cp_pt(pressure,temperature,si, si)

	def test_Case1(self):
		temperature = 0
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.cp_pt(pressure,temperature,si,si)

	def test_Case2(self):
		temperature = 800
		pressure =    100
		# any exception raised will fail the test
		WatpropPy.cp_pt(pressure,temperature,si,si)

	def test_Case3(self):
		temperature = 800
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.cp_pt(pressure,temperature,si,si)

	def test_Case4(self):
		temperature = 2000
		pressure =    50
		# any exception raised will fail the test
		WatpropPy.cp_pt(pressure,temperature,si,si)

	def test_Case5(self):
		temperature = 2000
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.cp_pt(pressure,temperature,si,si)

	def test_Case6(self):
		temperature = 647.096
		pressure =    22.064
		# any exception raised will fail the test
		WatpropPy.cp_pt(pressure,temperature,si,si)

	def test_Case7(self):
		temperature = 0
		pressure =    100.1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.cp_pt(pressure,temperature,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

	def test_Case8(self):
		temperature = -1
		pressure =    1e-3
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.cp_pt(pressure,temperature,si,si)
		assert "temperature out of bounds" in str(excinfo.value)

	def test_Case9(self):
		temperature = 800
		pressure =    100.1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.cp_pt(pressure,temperature,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

	def test_Case10(self):
		temperature = 800
		pressure =    0
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.cp_pt(pressure,temperature,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

	def test_Case11(self):
		temperature = 2000
		pressure =    50.01
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.cp_pt(pressure,temperature,si,si)
		assert "pressure/temperature combination out of bounds" in str(excinfo.value)

	def test_Case12(self):
		temperature = 2000.1
		pressure =    1e-3
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.cp_pt(pressure,temperature,si,si)
		assert "temperature out of bounds" in str(excinfo.value)

class TestViscosity():
	def test_Case0(self):
		temperature = 0
		pressure =    100
		# any exception raised will fail the test
		WatpropPy.vis_pt(pressure,temperature,si, si)

	def test_Case1(self):
		temperature = 0
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.vis_pt(pressure,temperature,si,si)

	def test_Case2(self):
		temperature = 800
		pressure =    100
		# any exception raised will fail the test
		WatpropPy.vis_pt(pressure,temperature,si,si)

	def test_Case3(self):
		temperature = 800
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.vis_pt(pressure,temperature,si,si)

	def test_Case4(self):
		temperature = 2000
		pressure =    50
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.vis_pt(pressure,temperature,si,si)
		assert "shear viscosity calculation is not valid in portions of Region 5" in str(excinfo.value)

	def test_Case5(self):
		temperature = 2000
		pressure =    1e-3
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.vis_pt(pressure,temperature,si,si)
		assert "shear viscosity calculation is not valid in portions of Region 5" in str(excinfo.value)

	def test_Case6(self):
		temperature = 647.096
		pressure =    22.064
		# any exception raised will fail the test
		WatpropPy.vis_pt(pressure,temperature,si,si)

	def test_Case7(self):
		temperature = 0
		pressure =    100.1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.vis_pt(pressure,temperature,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

	def test_Case8(self):
		temperature = -1
		pressure =    1e-3
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.vis_pt(pressure,temperature,si,si)
		assert "temperature out of bounds" in str(excinfo.value)

	def test_Case9(self):
		temperature = 800
		pressure =    100.1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.vis_pt(pressure,temperature,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

	def test_Case10(self):
		temperature = 800
		pressure =    0
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.vis_pt(pressure,temperature,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

	def test_Case11(self):
		temperature = 2000
		pressure =    50.01
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.vis_pt(pressure,temperature,si,si)
		assert "pressure/temperature combination out of bounds" in str(excinfo.value)

	def test_Case12(self):
		temperature = 2000.1
		pressure =    1e-3
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.vis_pt(pressure,temperature,si,si)
		assert "temperature out of bounds" in str(excinfo.value)

class TestConductivity():
	def test_Case0(self):
		temperature = 0
		pressure =    100
		# any exception raised will fail the test
		WatpropPy.k_pt(pressure,temperature,si, si)

	def test_Case1(self):
		temperature = 0
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.k_pt(pressure,temperature,si,si)

	def test_Case2(self):
		temperature = 800
		pressure =    100
		# any exception raised will fail the test
		WatpropPy.k_pt(pressure,temperature,si,si)

	def test_Case3(self):
		temperature = 800
		pressure =    1e-3
		# any exception raised will fail the test
		WatpropPy.k_pt(pressure,temperature,si,si)

	def test_Case4(self):
		temperature = 2000
		pressure =    50
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.k_pt(pressure,temperature,si,si)
		assert "invalid temperature in k_pt" in str(excinfo.value)

	def test_Case5(self):
		temperature = 2000
		pressure =    1e-3
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.k_pt(pressure,temperature,si,si)
		assert "invalid temperature in k_pt" in str(excinfo.value)

	def test_Case6(self):
		temperature = 647.096
		pressure =    22.064
		# any exception raised will fail the test
		WatpropPy.k_pt(pressure,temperature,si,si)

	def test_Case7(self):
		temperature = 0
		pressure =    100.1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.k_pt(pressure,temperature,si,si)
		assert "invalid pressure in k_pt" in str(excinfo.value)

	def test_Case8(self):
		temperature = -1
		pressure =    1e-3
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.k_pt(pressure,temperature,si,si)
		assert "invalid temperature in k_pt" in str(excinfo.value)

	def test_Case9(self):
		temperature = 800
		pressure =    100.1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.k_pt(pressure,temperature,si,si)
		assert "invalid pressure in k_pt" in str(excinfo.value)

	def test_Case10(self):
		temperature = 800
		pressure =    0
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.k_pt(pressure,temperature,si,si)
		assert "invalid pressure in k_pt" in str(excinfo.value)

	def test_Case11(self):
		temperature = 2000
		pressure =    50.01
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.k_pt(pressure,temperature,si,si)
		assert "invalid temperature in k_pt" in str(excinfo.value)

	def test_Case12(self):
		temperature = 2000.1
		pressure =    1e-3
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.k_pt(pressure,temperature,si,si)
		assert "invalid temperature in k_pt" in str(excinfo.value)
