# test WatpropPy at IAPWS statepoints as a function of saturation pressure
import pytest

import WatpropPy

pytestmark = pytest.mark.basic

si = WatpropPy.Units.SI
english = WatpropPy.Units.ENGLISH

#=============================================================
class TestTemperature():
	def test_Case0(self):
		pressure =    1E-3
		# any exception raised will fail the test
		WatpropPy.T_P(pressure,si,si)

	def test_Case1(self):
		pressure =    22
		# any exception raised will fail the test
		WatpropPy.T_P(pressure,si,si)

	def test_Case2(self):
		pressure =    22.064
		# any exception raised will fail the test
		WatpropPy.T_P(pressure,si,si)

	def test_Case3(self):
		pressure =    0
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.T_P(pressure,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

	def test_Case4(self):
		pressure =    23
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.T_P(pressure,si,si)
		assert "pressure out of bounds" in str(excinfo.value)

class TestHf():
	def test_Case0(self):
		pressure =    1E-3
		# any exception raised will fail the test
		WatpropPy.HF_P(pressure,si,si)

	def test_Case1(self):
		pressure =    22
		# any exception raised will fail the test
		WatpropPy.HF_P(pressure,si,si)

	def test_Case2(self):
		pressure =    22.064
		# any exception raised will fail the test
		WatpropPy.HF_P(pressure,si,si)

	def test_Case3(self):
		pressure =    0
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.HF_P(pressure,si,si)
		assert "invalid pressure in hf_p" in str(excinfo.value)

	def test_Case4(self):
		pressure =    23
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.HF_P(pressure,si,si)
		assert "invalid pressure in hf_p" in str(excinfo.value)

class TestHg():
	def test_Case0(self):
		pressure =    1E-3
		# any exception raised will fail the test
		WatpropPy.HG_P(pressure,si,si)

	def test_Case1(self):
		pressure =    22
		# any exception raised will fail the test
		WatpropPy.HG_P(pressure,si,si)

	def test_Case2(self):
		pressure =    22.064
		# any exception raised will fail the test
		WatpropPy.HG_P(pressure,si,si)

	def test_Case3(self):
		pressure =    0
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.HG_P(pressure,si,si)
		assert "invalid pressure in hg_p" in str(excinfo.value)

	def test_Case4(self):
		pressure =    23
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.HG_P(pressure,si,si)
		assert "invalid pressure in hg_p" in str(excinfo.value)

class TestSf():
	def test_Case0(self):
		pressure =    1E-3
		# any exception raised will fail the test
		WatpropPy.SF_P(pressure,si,si)

	def test_Case1(self):
		pressure =    22
		# any exception raised will fail the test
		WatpropPy.SF_P(pressure,si,si)

	def test_Case2(self):
		pressure =    22.064
		# any exception raised will fail the test
		WatpropPy.SF_P(pressure,si,si)

	def test_Case3(self):
		pressure =    0
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.SF_P(pressure,si,si)
		assert "invalid pressure in sf_p" in str(excinfo.value)

	def test_Case4(self):
		pressure =    23
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.SF_P(pressure,si,si)
		assert "invalid pressure in sf_p" in str(excinfo.value)

class TestSg():
	def test_Case0(self):
		pressure =    1E-3
		# any exception raised will fail the test
		WatpropPy.SG_P(pressure,si,si)

	def test_Case1(self):
		pressure =    22
		# any exception raised will fail the test
		WatpropPy.SG_P(pressure,si,si)

	def test_Case2(self):
		pressure =    22.064
		# any exception raised will fail the test
		WatpropPy.SG_P(pressure,si,si)

	def test_Case3(self):
		pressure =    0
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.SG_P(pressure,si,si)
		assert "invalid pressure in sg_p" in str(excinfo.value)

	def test_Case4(self):
		pressure =    23
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.SG_P(pressure,si,si)
		assert "invalid pressure in sg_p" in str(excinfo.value)

class TestVf():
	def test_Case0(self):
		pressure =    1E-3
		# any exception raised will fail the test
		WatpropPy.VF_P(pressure,si,si)

	def test_Case1(self):
		pressure =    22
		# any exception raised will fail the test
		WatpropPy.VF_P(pressure,si,si)

	def test_Case2(self):
		pressure =    22.064
		# any exception raised will fail the test
		WatpropPy.VF_P(pressure,si,si)

	def test_Case3(self):
		pressure =    0
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.VF_P(pressure,si,si)
		assert "invalid pressure in vf_p" in str(excinfo.value)

	def test_Case4(self):
		pressure =    23
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.VF_P(pressure,si,si)
		assert "invalid pressure in vf_p" in str(excinfo.value)

class TestVg():
	def test_Case0(self):
		pressure =    1E-3
		# any exception raised will fail the test
		WatpropPy.VG_P(pressure,si,si)

	def test_Case1(self):
		pressure =    22
		# any exception raised will fail the test
		WatpropPy.VG_P(pressure,si,si)

	def test_Case2(self):
		pressure =    22.064
		# any exception raised will fail the test
		WatpropPy.VG_P(pressure,si,si)

	def test_Case3(self):
		pressure =    0
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.VG_P(pressure,si,si)
		assert "invalid pressure in vg_p" in str(excinfo.value)

	def test_Case4(self):
		pressure =    23
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.VG_P(pressure,si,si)
		assert "invalid pressure in vg_p" in str(excinfo.value)




