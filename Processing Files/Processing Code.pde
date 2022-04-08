import processing.serial.*;
import ddf.minim.*;
 
Serial myPort;  // For reading port
Minim minim;    // For sound

AudioPlayer player1;
AudioPlayer player2;
AudioPlayer player3;

// Codes from Arduino
byte audio1 = 1;
byte noaudio1 = 2;
byte audio2 = 3;
byte noaudio2 = 4;
byte audio3 = 5;
byte noaudio3 = 6;
 
void setup()
{
  size(400, 400);  // Size of pop up

  myPort = new Serial(this, "COM3", 9600);
  minim = new Minim(this);
 
  // Load audio files
  player1 = minim.loadFile("red_crayon.wav");
  player2 = minim.loadFile("yellow_crayon.wav");
  player3 = minim.loadFile("blue_crayon.wav");
}
 
void draw() {
  background(0); 
  
  while (myPort.available() > 0) {
    int inByte = myPort.read();
    
    // BUTTON 1
    if (inByte == audio1) {
      player1.play();
      
      // Draw crayon
      fill(255, 0, 0);
      noStroke();
      rect(175, 120, 50, 200, 0, 0, 12, 12);
      triangle(200, 100, 175, 120, 225, 120);
      fill(0);
      circle(190, 150, 3);
      circle(210, 150, 3);
      stroke(100);
      line(190, 170, 210, 170);
    }
      
    if (inByte == noaudio1) {
      player1.pause();
      player1.rewind();
    }
    
    // BUTTON 2
    if (inByte == audio2) {
      player2.play();
      
      // Draw crayon
      fill(255, 255, 0);
      noStroke();
      rect(175, 120, 50, 200, 0, 0, 12, 12);
      triangle(200, 100, 175, 120, 225, 120);
      fill(0);
      circle(190, 150, 3);
      circle(210, 150, 3);
      stroke(100);
      line(190, 170, 210, 170);
    }
    if (inByte == noaudio2) {
      player2.pause();
      player2.rewind();
    }
    
    // BUTTON 3
    if (inByte == audio3){
      player3.play();
      
      // Draw crayon
      fill(65,105,225);
      noStroke();
      rect(175, 120, 50, 200, 0, 0, 12, 12);
      triangle(200, 100, 175, 120, 225, 120);
      fill(0);
      circle(190, 150, 3);
      circle(210, 150, 3);
      stroke(100);
      line(190, 170, 210, 170);
    }
    if(inByte == noaudio3) {
      player3.pause();
      player3.rewind();
    }
  }
}

void stop()
{
  // always close Minim audio classes when you are done with them
  player1.close();
  player2.close();
  player3.close();
  
  // always stop Minim before exiting
  minim.stop();

  super.stop();
}
