ALL = bin/make_invoice_1_normal \
      bin/make_invoice_2_interface \
      bin/make_invoice_3_inheritance \
      bin/destruct

all: $(ALL)

clean:
	rm -f a.out bin/*

bin/make_invoice_1_normal: src/make_invoice_1_normal.cpp
	g++ -o bin/make_invoice_1_normal src/make_invoice_1_normal.cpp 

bin/make_invoice_2_interface: src/make_invoice_2_interface.cpp
	g++ -o bin/make_invoice_2_interface src/make_invoice_2_interface.cpp 

bin/make_invoice_3_inheritance: src/make_invoice_3_inheritance.cpp
	g++ -o bin/make_invoice_3_inheritance src/make_invoice_3_inheritance.cpp 

bin/destruct: src/destruct.cpp
	g++ -o bin/destruct src/destruct.cpp 

