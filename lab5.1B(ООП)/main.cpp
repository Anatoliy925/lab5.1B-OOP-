#include <iostream>
#include "Complex.hpp"
#include "Exception.hpp"
#include "Exception_anc.hpp"
int main() {
    bool result;
    
    Complex t, r;

    do {
        try {
            
            result = true;
            cout << "Assign first complex number: " << endl;
            cin >> t;
            cout << "Assign second complex number: " << endl;
            cin >> r;
            cout << "Result of division: " << endl << div(t, r);
            cout << "Result of subtraction: " << endl << sub(t, r);
            cout << "First number conjucted: " << endl << t.conj();
            cout << "Second number conjucted: " << endl << r.conj();

            cout << "--t\n" << --t << endl;
            cout << "++t\n" << ++t << endl;
            cout << "t++\n" << t++ << endl;
            cout << "t--\n" << t-- << endl;
        }
        catch (Exception_anc* a) {
            result = false;
            cerr << a->What() << endl;
        }
        catch (Exception& e)
        {
            result = false;
            cerr << e.What() << endl;
        }
        catch (bad_exception e)
        {
            result = false;
            cerr << e.what() << endl;
            
        }
      
    } while (!result);
        cout << endl<<t<<endl;
        
    
        
       

        

        return 0;
}
