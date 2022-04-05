cdef extern from "wat.h":
    enum Units:
        METRIC = 0
        ENGLISH = 1
    double _H_PT(double p, double t, Units iunits, Units ounits)
    double _V_PT(double p, double t, Units iunits, Units ounits)
    double _W_PT(double p, double t, Units iunits, Units ounits)
    double _HF_T(double t, Units iunits, Units ounits)
    double _HG_T(double t, Units iunits, Units ounits)
    double _P_T(double t, Units iunits, Units ounits)
    double _T_P(double p, Units iunits, Units ounits)
    double _S_PT(double p, double t, Units iunits, Units ounits)
    double _CP_PT(double p, double t, Units iunits, Units ounits)
    double _VIS_PT(double p, double t, Units iunits, Units ounits)
    double _K_PT(double p, double t, Units iunits, Units ounits)
    double _SF_T(double t, Units iunits, Units ounits)
    double _SG_T(double t, Units iunits, Units ounits)
    double _HF_P(double p, Units iunits, Units ounits)
    double _HG_P(double p, Units iunits, Units ounits)
    double _VF_P(double p, Units iunits, Units ounits)
    double _VG_P(double p, Units iunits, Units ounits)
    double _SF_P(double p, Units iunits, Units ounits)
    double _SG_P(double p, Units iunits, Units ounits)
    double _T_PH(double p, double h, Units iunits, Units ounits)
    double _V_PH(double p, double h, Units iunits, Units ounits)
    double _S_PH(double p, double h, Units iunits, Units ounits)



