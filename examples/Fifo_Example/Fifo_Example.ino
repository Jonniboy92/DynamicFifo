  #include <DynamicFifo.h>
  
  #define Array_Size_Chare 20
  #define Buffer_Size 250
  
  DynamicFifo<char[Array_Size_Chare]> DynamicChar(Buffer_Size);
  
void setup() {
  // Start Serial
    Serial.begin(9600);
    while(!Serial);
    Serial.println("Restart");
}

void loop() {
  // STATUS
  Serial.println("--------------------------------------------");
  Serial.print("Status:\t-Empty=");
  Serial.print(DynamicChar.isEmpty());
  Serial.print("\t-Full=");
  Serial.print(DynamicChar.isFull());
  Serial.print("\t-Lenght=");
  Serial.println(DynamicChar.length());
  
  // Select
  Serial.print("Select:\t[E]nqueue massage, [D]equeue:");
  while(!Serial.available());
  String input = Serial.readStringUntil('\n');
  char Select = input.charAt(0);
  
  // Enqueue
  if (Select == 'E'){
    Serial.println("[E] selectet");
    Serial.print("Enter text to Stor:");
    while(!Serial.available());
    String text = Serial.readStringUntil('\n');
    Serial.println(text);
    char Input[Array_Size_Chare];
    text.toCharArray(Input, Array_Size_Chare); 
    DynamicChar.enqueue(Input);
  // Dequeue
  } else if (Select == 'D'){
    Serial.println("[D] selectet");
    Serial.print("Dequeue Text:");
    char Output[Array_Size_Chare];
    DynamicChar.dequeue(Output);
    Serial.println((String)Output);
  // Wrong select
  } else {
    Serial.println("Wrong Selection!");  
  }

}
