# test watprop at IAPWS statepoints as a function of P,T
import pytest
import sys

import WatpropPy

si = WatpropPy.units.si
english = WatpropPy.units.english

tol = 1e-7
englishPressure = 2000  #psia
englishTemperature = 300  #deg F

@pytest.fixture
def englishResults():
	englishResults = {}
	englishResults['h_pt'] = WatpropPy.h_pt(englishPressure, englishTemperature)
	englishResults['s_pt'] = WatpropPy.s_pt(englishPressure, englishTemperature)
	englishResults['v_pt'] = WatpropPy.v_pt(englishPressure, englishTemperature)
	englishResults['cp_pt'] = WatpropPy.cp_pt(englishPressure, englishTemperature)
	englishResults['vis_pt'] = WatpropPy.vis_pt(englishPressure, englishTemperature)
	englishResults['k_pt'] = WatpropPy.k_pt(englishPressure, englishTemperature)
	englishResults['w_pt'] = WatpropPy.w_pt(englishPressure, englishTemperature)
	englishResults['p_t'] = WatpropPy.p_t(englishTemperature)
	englishResults['t_p'] = WatpropPy.t_p(englishPressure)
	englishResults['hf_t'] = WatpropPy.hf_t(englishTemperature)
	englishResults['hg_t'] = WatpropPy.hg_t(englishTemperature)
	englishResults['sf_t'] = WatpropPy.sf_t(englishTemperature)
	englishResults['sg_t'] = WatpropPy.sg_t(englishTemperature)
	englishResults['vf_t'] = WatpropPy.vf_t(englishTemperature)
	englishResults['vg_t'] = WatpropPy.vg_t(englishTemperature)
	englishResults['hf_p'] = WatpropPy.hf_p(englishPressure)
	englishResults['hg_p'] = WatpropPy.hg_p(englishPressure)
	englishResults['sf_p'] = WatpropPy.sf_p(englishPressure)
	englishResults['sg_p'] = WatpropPy.sg_p(englishPressure)
	englishResults['vf_p'] = WatpropPy.vf_p(englishPressure)
	englishResults['vg_p'] = WatpropPy.vg_p(englishPressure)
	englishResults['t_ph'] = WatpropPy.t_ph(englishPressure, englishResults['h_pt'])
	englishResults['v_ph'] = WatpropPy.v_ph(englishPressure, englishResults['h_pt'])
	englishResults['s_ph'] = WatpropPy.s_ph(englishPressure, englishResults['h_pt'])
	yield englishResults

def test_english_to_missing(englishResults):
	assert WatpropPy.h_pt(englishPressure,englishTemperature, english) == englishResults['h_pt']
	assert WatpropPy.s_pt(englishPressure,englishTemperature, english) == englishResults['s_pt']
	assert WatpropPy.v_pt(englishPressure,englishTemperature, english) == englishResults['v_pt']
	assert WatpropPy.cp_pt(englishPressure,englishTemperature, english) == englishResults['cp_pt']
	assert WatpropPy.vis_pt(englishPressure,englishTemperature, english) == englishResults['vis_pt']
	assert WatpropPy.k_pt(englishPressure,englishTemperature, english) == englishResults['k_pt']
	assert WatpropPy.w_pt(englishPressure,englishTemperature, english) == englishResults['w_pt']
	assert WatpropPy.p_t(englishTemperature, english) == englishResults['p_t']
	assert WatpropPy.t_p(englishPressure, english) == englishResults['t_p']
	assert WatpropPy.hf_t(englishTemperature, english) == englishResults['hf_t']
	assert WatpropPy.hg_t(englishTemperature, english) == englishResults['hg_t']
	assert WatpropPy.sf_t(englishTemperature, english) == englishResults['sf_t']
	assert WatpropPy.sg_t(englishTemperature, english) == englishResults['sg_t']
	assert WatpropPy.vf_t(englishTemperature, english) == englishResults['vf_t']
	assert WatpropPy.vg_t(englishTemperature, english) == englishResults['vg_t']
	assert WatpropPy.hf_p(englishPressure, english) == englishResults['hf_p']
	assert WatpropPy.hg_p(englishPressure, english) == englishResults['hg_p']
	assert WatpropPy.sf_p(englishPressure, english) == englishResults['sf_p']
	assert WatpropPy.sg_p(englishPressure, english) == englishResults['sg_p']
	assert WatpropPy.vf_p(englishPressure, english) == englishResults['vf_p']
	assert WatpropPy.vg_p(englishPressure, english) == englishResults['vg_p']
	assert WatpropPy.t_ph(englishPressure, englishResults['h_pt'], english) == englishResults['t_ph']
	assert WatpropPy.v_ph(englishPressure, englishResults['h_pt'], english) == englishResults['v_ph']
	assert WatpropPy.s_ph(englishPressure, englishResults['h_pt'], english) == englishResults['s_ph']

def test_english_to_english(englishResults):
	assert WatpropPy.h_pt(englishPressure,englishTemperature, english, english) == englishResults['h_pt']
	assert WatpropPy.s_pt(englishPressure,englishTemperature, english, english) == englishResults['s_pt']
	assert WatpropPy.v_pt(englishPressure,englishTemperature, english, english) == englishResults['v_pt']
	assert WatpropPy.cp_pt(englishPressure,englishTemperature, english, english) == englishResults['cp_pt']
	assert WatpropPy.vis_pt(englishPressure,englishTemperature, english, english) == englishResults['vis_pt']
	assert WatpropPy.k_pt(englishPressure,englishTemperature, english, english) == englishResults['k_pt']
	assert WatpropPy.w_pt(englishPressure,englishTemperature, english, english) == englishResults['w_pt']
	assert WatpropPy.p_t(englishTemperature, english, english) == englishResults['p_t']
	assert WatpropPy.t_p(englishPressure, english, english) == englishResults['t_p']
	assert WatpropPy.hf_t(englishTemperature, english, english) == englishResults['hf_t']
	assert WatpropPy.hg_t(englishTemperature, english, english) == englishResults['hg_t']
	assert WatpropPy.sf_t(englishTemperature, english, english) == englishResults['sf_t']
	assert WatpropPy.sg_t(englishTemperature, english, english) == englishResults['sg_t']
	assert WatpropPy.vf_t(englishTemperature, english, english) == englishResults['vf_t']
	assert WatpropPy.vg_t(englishTemperature, english, english) == englishResults['vg_t']
	assert WatpropPy.hf_p(englishPressure, english, english) == englishResults['hf_p']
	assert WatpropPy.hg_p(englishPressure, english, english) == englishResults['hg_p']
	assert WatpropPy.sf_p(englishPressure, english, english) == englishResults['sf_p']
	assert WatpropPy.sg_p(englishPressure, english, english) == englishResults['sg_p']
	assert WatpropPy.vf_p(englishPressure, english, english) == englishResults['vf_p']
	assert WatpropPy.vg_p(englishPressure, english, english) == englishResults['vg_p']
	assert WatpropPy.t_ph(englishPressure, englishResults['h_pt'], english, english) == englishResults['t_ph']
	assert WatpropPy.v_ph(englishPressure, englishResults['h_pt'], english, english) == englishResults['v_ph']
	assert WatpropPy.s_ph(englishPressure, englishResults['h_pt'], english, english) == englishResults['s_ph']

def test_english_to_si(englishResults):
	si_to_english_p = 145.0377
	si_to_english_tmult = 1.8
	si_to_english_tadd = -459.67
	si_to_centigrade = -273.15
	si_to_english_h = 1./2.326
	si_to_english_s = 1./4.1868
	si_to_english_v = 16.01846
	si_to_english_cp = 1./4.1868
	si_to_english_w = 3.2808399
	si_to_english_vis = 6.719690e-1
	si_to_english_k = 0.5777893
	assert WatpropPy.h_pt(englishPressure,englishTemperature, english, si) * si_to_english_h == englishResults['h_pt']
	assert WatpropPy.s_pt(englishPressure,englishTemperature, english, si) * si_to_english_s == englishResults['s_pt']
	assert WatpropPy.v_pt(englishPressure,englishTemperature, english, si) * si_to_english_v == englishResults['v_pt']
	assert WatpropPy.cp_pt(englishPressure,englishTemperature, english, si) * si_to_english_cp == englishResults['cp_pt']
# note the 1000000!
	assert WatpropPy.vis_pt(englishPressure,englishTemperature, english, si)*  si_to_english_vis /1000000 == pytest.approx(englishResults['vis_pt'],rel=tol)
# note the 1000!
	assert WatpropPy.k_pt(englishPressure,englishTemperature, english, si) * si_to_english_k /1000 == englishResults['k_pt']
	assert WatpropPy.w_pt(englishPressure,englishTemperature, english, si) * si_to_english_w == englishResults['w_pt']
	assert WatpropPy.p_t(englishTemperature, english, si) * si_to_english_p == englishResults['p_t']
	assert (WatpropPy.t_p(englishPressure, english, si) - si_to_centigrade) * si_to_english_tmult + si_to_english_tadd == englishResults['t_p']
	assert WatpropPy.hf_t(englishTemperature, english, si) * si_to_english_h == englishResults['hf_t']
	assert WatpropPy.hg_t(englishTemperature, english, si) * si_to_english_h == englishResults['hg_t']
	assert WatpropPy.sf_t(englishTemperature, english, si) * si_to_english_s == englishResults['sf_t']
	assert WatpropPy.sg_t(englishTemperature, english, si) * si_to_english_s == englishResults['sg_t']
	assert WatpropPy.vf_t(englishTemperature, english, si) * si_to_english_v == englishResults['vf_t']
	assert WatpropPy.vg_t(englishTemperature, english, si) * si_to_english_v == englishResults['vg_t']
	assert WatpropPy.hf_p(englishPressure, english, si) * si_to_english_h == englishResults['hf_p']
	assert WatpropPy.hg_p(englishPressure, english, si) * si_to_english_h == englishResults['hg_p']
	assert WatpropPy.sf_p(englishPressure, english, si) * si_to_english_s == englishResults['sf_p']
	assert WatpropPy.sg_p(englishPressure, english, si) * si_to_english_s == englishResults['sg_p']
	assert WatpropPy.vf_p(englishPressure, english, si) * si_to_english_v == englishResults['vf_p']
	assert WatpropPy.vg_p(englishPressure, english, si) * si_to_english_v == englishResults['vg_p']
	assert (WatpropPy.t_ph(englishPressure, englishResults['h_pt'], english, si) - si_to_centigrade) * si_to_english_tmult + si_to_english_tadd == pytest.approx(englishResults['t_ph'],rel=tol)
	assert WatpropPy.v_ph(englishPressure, englishResults['h_pt'], english, si) * si_to_english_v == englishResults['v_ph']
	assert WatpropPy.s_ph(englishPressure, englishResults['h_pt'], english, si) * si_to_english_s== englishResults['s_ph']

def test_si_to_si(englishResults):
	si_to_english_p = 145.0377
	si_to_english_tmult = 1.8
	si_to_english_tadd = -459.67
	si_to_centigrade = -273.15
	si_to_english_h = 1./2.326
	si_to_english_s = 1./4.1868
	si_to_english_v = 16.01846
	si_to_english_cp = 1./4.1868
	si_to_english_w = 3.2808399
	si_to_english_vis = 6.719690e-1
	si_to_english_k = 0.5777893
	siPressure = englishPressure /si_to_english_p
	siTemperature = (englishTemperature - si_to_english_tadd) / si_to_english_tmult + si_to_centigrade
	assert WatpropPy.h_pt(siPressure,siTemperature, si, si) * si_to_english_h == englishResults['h_pt']
	assert WatpropPy.s_pt(siPressure,siTemperature, si, si) * si_to_english_s == englishResults['s_pt']
	assert WatpropPy.v_pt(siPressure,siTemperature, si, si) * si_to_english_v == englishResults['v_pt']
	assert WatpropPy.cp_pt(siPressure,siTemperature, si, si) * si_to_english_cp == englishResults['cp_pt']
# note the 1000000!
	assert WatpropPy.vis_pt(siPressure,siTemperature, si, si)*  si_to_english_vis /1000000 == pytest.approx(englishResults['vis_pt'],rel=tol)
# note the 1000!
	assert WatpropPy.k_pt(siPressure,siTemperature, si, si) * si_to_english_k /1000 == englishResults['k_pt']
	assert WatpropPy.w_pt(siPressure,siTemperature, si, si) * si_to_english_w == englishResults['w_pt']
	assert WatpropPy.p_t(siTemperature, si, si) * si_to_english_p == englishResults['p_t']
	assert (WatpropPy.t_p(siPressure, si, si) - si_to_centigrade) * si_to_english_tmult + si_to_english_tadd == englishResults['t_p']
	assert WatpropPy.hf_t(siTemperature, si, si) * si_to_english_h == englishResults['hf_t']
	assert WatpropPy.hg_t(siTemperature, si, si) * si_to_english_h == englishResults['hg_t']
	assert WatpropPy.sf_t(siTemperature, si, si) * si_to_english_s == englishResults['sf_t']
	assert WatpropPy.sg_t(siTemperature, si, si) * si_to_english_s == englishResults['sg_t']
	assert WatpropPy.vf_t(siTemperature, si, si) * si_to_english_v == englishResults['vf_t']
	assert WatpropPy.vg_t(siTemperature, si, si) * si_to_english_v == englishResults['vg_t']
	assert WatpropPy.hf_p(siPressure, si, si) * si_to_english_h == englishResults['hf_p']
	assert WatpropPy.hg_p(siPressure, si, si) * si_to_english_h == englishResults['hg_p']
	assert WatpropPy.sf_p(siPressure, si, si) * si_to_english_s == englishResults['sf_p']
	assert WatpropPy.sg_p(siPressure, si, si) * si_to_english_s == englishResults['sg_p']
	assert WatpropPy.vf_p(siPressure, si, si) * si_to_english_v == englishResults['vf_p']
	assert WatpropPy.vg_p(siPressure, si, si) * si_to_english_v == englishResults['vg_p']
	assert (WatpropPy.t_ph(siPressure, englishResults['h_pt']/si_to_english_h, si, si) - si_to_centigrade) * si_to_english_tmult + si_to_english_tadd == pytest.approx(englishResults['t_ph'],rel=tol)
	assert WatpropPy.v_ph(siPressure, englishResults['h_pt']/si_to_english_h, si, si) * si_to_english_v == englishResults['v_ph']
	assert WatpropPy.s_ph(siPressure, englishResults['h_pt']/si_to_english_h, si, si) * si_to_english_s== englishResults['s_ph']

def test_si_to_missing(englishResults):
	si_to_english_p = 145.0377
	si_to_english_tmult = 1.8
	si_to_english_tadd = -459.67
	si_to_centigrade = -273.15
	si_to_english_h = 1./2.326
	siPressure = englishPressure /si_to_english_p
	siTemperature = (englishTemperature - si_to_english_tadd) / si_to_english_tmult + si_to_centigrade
	assert WatpropPy.h_pt(siPressure,siTemperature, si) == englishResults['h_pt']
	assert WatpropPy.s_pt(siPressure,siTemperature, si) == englishResults['s_pt']
	assert WatpropPy.v_pt(siPressure,siTemperature, si) == englishResults['v_pt']
	assert WatpropPy.cp_pt(siPressure,siTemperature, si) == englishResults['cp_pt']
	assert WatpropPy.vis_pt(siPressure,siTemperature, si) == englishResults['vis_pt']
	assert WatpropPy.k_pt(siPressure,siTemperature, si)  == englishResults['k_pt']
	assert WatpropPy.w_pt(siPressure,siTemperature, si)  == englishResults['w_pt']
	assert WatpropPy.p_t(siTemperature, si)  == englishResults['p_t']
	assert WatpropPy.t_p(siPressure, si) == englishResults['t_p']
	assert WatpropPy.hf_t(siTemperature, si) == englishResults['hf_t']
	assert WatpropPy.hg_t(siTemperature, si) == englishResults['hg_t']
	assert WatpropPy.sf_t(siTemperature, si) == englishResults['sf_t']
	assert WatpropPy.sg_t(siTemperature, si) == englishResults['sg_t']
	assert WatpropPy.vf_t(siTemperature, si) == englishResults['vf_t']
	assert WatpropPy.vg_t(siTemperature, si) == englishResults['vg_t']
	assert WatpropPy.hf_p(siPressure, si) == englishResults['hf_p']
	assert WatpropPy.hg_p(siPressure, si) == englishResults['hg_p']
	assert WatpropPy.sf_p(siPressure, si) == englishResults['sf_p']
	assert WatpropPy.sg_p(siPressure, si) == englishResults['sg_p']
	assert WatpropPy.vf_p(siPressure, si) == englishResults['vf_p']
	assert WatpropPy.vg_p(siPressure, si) == englishResults['vg_p']
	assert WatpropPy.t_ph(siPressure, englishResults['h_pt']/si_to_english_h, si) == englishResults['t_ph']
	assert WatpropPy.v_ph(siPressure, englishResults['h_pt']/si_to_english_h, si) == englishResults['v_ph']
	assert WatpropPy.s_ph(siPressure, englishResults['h_pt']/si_to_english_h, si) == englishResults['s_ph']

def test_si_to_english(englishResults):
	si_to_english_p = 145.0377
	si_to_english_tmult = 1.8
	si_to_english_tadd = -459.67
	si_to_centigrade = -273.15
	si_to_english_h = 1./2.326
	siPressure = englishPressure /si_to_english_p
	siTemperature = (englishTemperature - si_to_english_tadd) / si_to_english_tmult + si_to_centigrade
	assert WatpropPy.h_pt(siPressure,siTemperature, si, english) == englishResults['h_pt']
	assert WatpropPy.s_pt(siPressure,siTemperature, si, english) == englishResults['s_pt']
	assert WatpropPy.v_pt(siPressure,siTemperature, si, english) == englishResults['v_pt']
	assert WatpropPy.cp_pt(siPressure,siTemperature, si, english) == englishResults['cp_pt']
	assert WatpropPy.vis_pt(siPressure,siTemperature, si, english) == englishResults['vis_pt']
	assert WatpropPy.k_pt(siPressure,siTemperature, si, english)  == englishResults['k_pt']
	assert WatpropPy.w_pt(siPressure,siTemperature, si, english)  == englishResults['w_pt']
	assert WatpropPy.p_t(siTemperature, si, english)  == englishResults['p_t']
	assert WatpropPy.t_p(siPressure, si, english) == englishResults['t_p']
	assert WatpropPy.hf_t(siTemperature, si, english) == englishResults['hf_t']
	assert WatpropPy.hg_t(siTemperature, si, english) == englishResults['hg_t']
	assert WatpropPy.sf_t(siTemperature, si, english) == englishResults['sf_t']
	assert WatpropPy.sg_t(siTemperature, si, english) == englishResults['sg_t']
	assert WatpropPy.vf_t(siTemperature, si, english) == englishResults['vf_t']
	assert WatpropPy.vg_t(siTemperature, si, english) == englishResults['vg_t']
	assert WatpropPy.hf_p(siPressure, si, english) == englishResults['hf_p']
	assert WatpropPy.hg_p(siPressure, si, english) == englishResults['hg_p']
	assert WatpropPy.sf_p(siPressure, si, english) == englishResults['sf_p']
	assert WatpropPy.sg_p(siPressure, si, english) == englishResults['sg_p']
	assert WatpropPy.vf_p(siPressure, si, english) == englishResults['vf_p']
	assert WatpropPy.vg_p(siPressure, si, english) == englishResults['vg_p']
	assert WatpropPy.t_ph(siPressure, englishResults['h_pt']/si_to_english_h, si, english) == englishResults['t_ph']
	assert WatpropPy.v_ph(siPressure, englishResults['h_pt']/si_to_english_h, si, english) == englishResults['v_ph']
	assert WatpropPy.s_ph(siPressure, englishResults['h_pt']/si_to_english_h, si, english) == englishResults['s_ph']



