# ...distutils: sources=["wat.cpp"]
cimport wat

def H_PT(double p, double t, char * iunits, char * ounits):
    wat._H_PT(p, t, iunits, ounits)
