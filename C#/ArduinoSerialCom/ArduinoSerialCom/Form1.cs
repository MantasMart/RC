using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
//lemona variklis techvita aliuminio profilis ratai
namespace ArduinoSerialCom
{
    public partial class Form1 : Form
    {
        bool isConnected = false;
        string[] ports;
        string indata;
        PictureBox currentPB;
 
        public Form1()
        {
            InitializeComponent();
            currentPB = pictureBox1;
            ports = SerialPort.GetPortNames();

            for (int i = 0; i < ports.Length; i++) {
                comboBox1.Items.Add(ports[i]);
            }

            if (ports != null) comboBox1.SelectedItem = ports[0];
        }


        private void button1_Click(object sender, EventArgs e)
        {
            if (isConnected == false) ConnectToArduino();
            else DisconnectFromArduino();
        }

        private void ConnectToArduino() {
            isConnected = true;
            string selectedPort = comboBox1.GetItemText(comboBox1.SelectedItem);
            serialPort1.PortName = selectedPort;
            serialPort1.BaudRate = 9600;
            serialPort1.Parity = Parity.None;
            serialPort1.DataBits = 8;
            serialPort1.StopBits = StopBits.One;

            serialPort1.Open();
            button1.Text = "Disconnect";
        }

        private void DisconnectFromArduino() {
            serialPort1.Write("p");
            Clear_Picturebox(currentPB);
            isConnected = false;
            serialPort1.Close();
            button1.Text = "Connect";
        }


        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {

            SerialPort sp = (SerialPort)sender;
            indata = sp.ReadExisting();
            textBox1.Invoke(new Action(() => textBox1.AppendText(indata)));
           
               if (indata == "1") Fill_Picturebox(pictureBox1);
               else if (indata == "2") Fill_Picturebox(pictureBox2);
               else if (indata == "3") Fill_Picturebox(pictureBox3);
               else if (indata == "4") Fill_Picturebox(pictureBox4);
               else if (indata == "5") Fill_Picturebox(pictureBox5);
               else if (indata == "6") Fill_Picturebox(pictureBox6);
               else if (indata == "7") Fill_Picturebox(pictureBox7);
               else if (indata == "8") Fill_Picturebox(pictureBox8);
               else if (indata == "0") Clear_Picturebox(currentPB);
               


        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
 
            if (isConnected == true) {

                if (e.KeyCode == Keys.W) serialPort1.Write("w");
                else if (e.KeyCode == Keys.A) serialPort1.Write("a");
                else if (e.KeyCode == Keys.S) serialPort1.Write("s");
                else if (e.KeyCode == Keys.D) serialPort1.Write("d");
                

            }
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            if (isConnected == true)
            {

                if (e.KeyCode == Keys.W) serialPort1.Write("u");
                else if (e.KeyCode == Keys.A) serialPort1.Write("h");
                else if (e.KeyCode == Keys.S) serialPort1.Write("j");
                else if (e.KeyCode == Keys.D) serialPort1.Write("k");

            }
        }

        private void Fill_Picturebox(PictureBox pb) {
            Clear_Picturebox(currentPB);
            Graphics gr = pb.CreateGraphics();
            gr.FillRectangle(Brushes.Red, 0, 0, pb.Width, pb.Height);
            gr.Dispose();
            currentPB = pb;
        }

        private void Clear_Picturebox(PictureBox pb){
            Graphics gr = pb.CreateGraphics();
            SolidBrush b = new SolidBrush(SystemColors.Control);
            gr.FillRectangle(b, 0, 0, pb.Width, pb.Height);
            gr.Dispose();
            b.Dispose();
   
        }
    }
}
