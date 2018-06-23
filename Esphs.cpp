#endif

#include "Esphs.h"

Esp::Esp(){

}

//----------------------------------------------------------------------------------------------------------------------

boolean Esp::reset(){

    Serial3.println("AT+RST");
    
    while(!Serial3.available()){ }

    if(Serial3.find("OK") ) {
    	
        Serial3.flush();
        
        return true;

    }

    else{

        return false;
  
    }
  
}

//----------------------------------------------------------------------------------------------

boolean Esp::setMode(int m){

    Serial3.println("AT+CWMODE="+String(m,DEC));

    while(!Serial3.available()){ }

    if(Serial3.find("OK") ) {
    	
        Serial3.flush();
        
        mode=m;

        return true;

    }

    else{

        return false;
  
    }
    
}

//-------------------------------------------------------------------------------------------------------------------------

void Esp::espNode(){

    if(Serial3.available()){
      
    String r=Serial3.readStringUntil('\n');
    
        Serial.println(r); 
    }

    else{ }

    if(Serial.available()){
      
    String r=Serial.readStringUntil('\n');
    
        Serial3.println(r);  
    }

    else { }

}

//-------------------------------------------------------------------------------------------------------------------------------

boolean Esp::setAP(String n, String p, int c, int e){

    Serial3.println("AT+CWSAP="+n+","+p+","+String(c,DEC)+","+String(e,DEC));

    while(!Serial3.available()){ }
    
    if(Serial3.find("OK") ) {
      
        Serial3.flush();
        ap.name=n;
        ap.password=p;
        ap.channel=c;
        ap.encrypt=e;
        
        return true;

    }

    else{

        return false;
  
    }
    
}

//-----------------------------------------------------------------------------------------------------------------

boolean Esp::setClient(String n, String p){

char c='"';

    Serial3.println("AT+JWSAP="+String(c)+n+String(c)+","+String(c)+p+String(c));

    while(!Serial3.available()){ }
    
    if(Serial3.find("OK") ) {
      
        Serial3.flush();
        client.name=n;
        client.password=p;
        
        return true;

    }

    else{

        return false;

    }
    
}

//-----------------------------------------------------------------------------------------------------------------------------

int Esp::getMode(){

return mode;

}

//--------------------------------------------------------------------------------------------------------------------------

boolean Esp::multiCon(int m){
	
	
    Serial.println("AT+CIPMUX="+String(m));
    
	while(!Serial3.available()){ }
    
    if(Serial3.find("OK")){
	
        Serial3.flush();
        
	    return true;

    }
    
    else {
    	
    	Serial3.flush();
    	
    	return false;
    	
	}
		
}

//----------------------------------------------------------------------------------------------------------------------------

boolean Esp::httpBegin(String t, String h, int p){

    char c ='"';
	
	Serial.println("AT+CIPSTART="+String(c)+t+String(c)+","+String(c)+h+String(c)+","+String(p));
    
	while(!Serial3.available()){ }
	
	if(Serial3.find("OK")){
		
		return true;
		
	}
	
	else{
	
	    return false; 
	
	}
	
}

//---------------------------------------------------------------------------------------------------------------------------------------

boolean Esp::httpSend(){
	
return true;
	
}
	



