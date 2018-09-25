ALL = make_invoice_1_normal make_invoice_2_interface make_invoice_3_inheritance destruct

all: $(ALL)

clean:
	rm -f $(ALL) a.out

make_invoice_1_normal: make_invoice_1_normal.cpp
	g++ -o make_invoice_1_normal make_invoice_1_normal.cpp 

make_invoice_2_interface: make_invoice_2_interface.cpp
	g++ -o make_invoice_2_interface make_invoice_2_interface.cpp 

make_invoice_3_inheritance: make_invoice_3_inheritance.cpp
	g++ -o make_invoice_3_inheritance make_invoice_3_inheritance.cpp 

destruct: destruct.cpp
	g++ -o destruct destruct.cpp 

