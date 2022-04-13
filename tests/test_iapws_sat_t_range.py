# test WatpropPy at IAPWS statepoints as a function of saturation temperature
import pytest

import WatpropPy

pytestmark = pytest.mark.basic

si = WatpropPy.Units.SI
english = WatpropPy.Units.ENGLISH

#=============================================================
class TestTemperature():
	def test_Case0(self):
		temperature =    0
		# any exception raised will fail the test
		WatpropPy.P_T(temperature,si,si)

	def test_Case1(self):
		temperature =    373
		# any exception raised will fail the test
		WatpropPy.P_T(temperature,si,si)

	def test_Case2(self):
		temperature =    373.946
		# any exception raised will fail the test
		WatpropPy.P_T(temperature,si,si)

	def test_Case3(self):
		temperature =    -1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.P_T(temperature,si,si)
		assert "temperature out of bounds" in str(excinfo.value)

	def test_Case4(self):
		temperature =    374
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.P_T(temperature,si,si)
		assert "temperature out of bounds" in str(excinfo.value)

class TestHf():
	def test_Case0(self):
		temperature =    0
		# any exception raised will fail the test
		WatpropPy.HF_T(temperature,si,si)

	def test_Case1(self):
		temperature =    373
		# any exception raised will fail the test
		WatpropPy.HF_T(temperature,si,si)

	def test_Case2(self):
		temperature =    373.946
		# any exception raised will fail the test
		WatpropPy.HF_T(temperature,si,si)

	def test_Case3(self):
		temperature =    -1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.HF_T(temperature,si,si)
		assert "invalid temperature in hf_t" in str(excinfo.value)

	def test_Case4(self):
		temperature =    374
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.HF_T(temperature,si,si)
		assert "invalid temperature in hf_t" in str(excinfo.value)

class TestHg():
	def test_Case0(self):
		temperature =    0
		# any exception raised will fail the test
		WatpropPy.HG_T(temperature,si,si)

	def test_Case1(self):
		temperature =    373
		# any exception raised will fail the test
		WatpropPy.HG_T(temperature,si,si)

	def test_Case2(self):
		temperature =    373.946
		# any exception raised will fail the test
		WatpropPy.HG_T(temperature,si,si)

	def test_Case3(self):
		temperature =    -1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.HG_T(temperature,si,si)
		assert "invalid temperature in hg_t" in str(excinfo.value)

	def test_Case4(self):
		temperature =    374
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.HG_T(temperature,si,si)
		assert "invalid temperature in hg_t" in str(excinfo.value)

class TestSf():
	def test_Case0(self):
		temperature =    0
		# any exception raised will fail the test
		WatpropPy.SF_T(temperature,si,si)

	def test_Case1(self):
		temperature =    373
		# any exception raised will fail the test
		WatpropPy.SF_T(temperature,si,si)

	def test_Case2(self):
		temperature =    373.946
		# any exception raised will fail the test
		WatpropPy.SF_T(temperature,si,si)

	def test_Case3(self):
		temperature =    -1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.SF_T(temperature,si,si)
		assert "invalid temperature in sf_t" in str(excinfo.value)

	def test_Case4(self):
		temperature =    374
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.SF_T(temperature,si,si)
		assert "invalid temperature in sf_t" in str(excinfo.value)

class TestSg():
	def test_Case0(self):
		temperature =    0
		# any exception raised will fail the test
		WatpropPy.SG_T(temperature,si,si)

	def test_Case1(self):
		temperature =    373
		# any exception raised will fail the test
		WatpropPy.SG_T(temperature,si,si)

	def test_Case2(self):
		temperature =    373.946
		# any exception raised will fail the test
		WatpropPy.SG_T(temperature,si,si)

	def test_Case3(self):
		temperature =    -1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.SG_T(temperature,si,si)
		assert "invalid temperature in sg_t" in str(excinfo.value)

	def test_Case4(self):
		temperature =    374
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.SG_T(temperature,si,si)
		assert "invalid temperature in sg_t" in str(excinfo.value)

class TestVf():
	def test_Case0(self):
		temperature =    0
		# any exception raised will fail the test
		WatpropPy.VF_T(temperature,si,si)

	def test_Case1(self):
		temperature =    373
		# any exception raised will fail the test
		WatpropPy.VF_T(temperature,si,si)

	def test_Case2(self):
		temperature =    373.946
		# any exception raised will fail the test
		WatpropPy.VF_T(temperature,si,si)

	def test_Case3(self):
		temperature =    -1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.VF_T(temperature,si,si)
		assert "invalid temperature in vf_t" in str(excinfo.value)

	def test_Case4(self):
		temperature =    374
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.VF_T(temperature,si,si)
		assert "invalid temperature in vf_t" in str(excinfo.value)

class TestVg():
	def test_Case0(self):
		temperature =    0
		# any exception raised will fail the test
		WatpropPy.VG_T(temperature,si,si)

	def test_Case1(self):
		temperature =    373
		# any exception raised will fail the test
		WatpropPy.VG_T(temperature,si,si)

	def test_Case2(self):
		temperature =    373.946
		# any exception raised will fail the test
		WatpropPy.VG_T(temperature,si,si)

	def test_Case3(self):
		temperature =    -1
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.VG_T(temperature,si,si)
		assert "invalid temperature in vg_t" in str(excinfo.value)

	def test_Case4(self):
		temperature =    374
		with pytest.raises(ValueError) as excinfo:
			WatpropPy.VG_T(temperature,si,si)
		assert "invalid temperature in vg_t" in str(excinfo.value)




