using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Numerics;

/// <summary>
/// Daniel Hazelton
/// 011513177
/// 9/20/2018
/// </summary>

namespace NotepadAppHazeltonHW3
{
    public partial class Form1 : Form
    {


        public Form1()
        {
           
           InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            textBox1.Text = "Welcome to my program!\n";

            
        }


        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            
        }

        

        private void button1_Click(object sender, EventArgs e)//save file
        {
            //open saved files with notepad to see text
            using (var sfd = new SaveFileDialog())
            {
                sfd.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
                sfd.FilterIndex = 2;

                if (sfd.ShowDialog() == DialogResult.OK)
                {
                    File.WriteAllText(sfd.FileName, textBox1.Text);
                }
            }

        }

        private void LoadText(TextReader sr)//Generic Loading Function
        {
            string line = "start";
            textBox1.Text = String.Empty;// clears text box
            
            while (line != null) {  //loads the text file sr into text box
                line = sr.ReadLine();
                if (line != null)
                {
                    textBox1.AppendText(line+"\n");
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)//LoadfromFile
        {

            //Test file in /NotepadAppHazeltonHW3
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            openFileDialog1.Filter = "Text Files|*.txt";
            openFileDialog1.Title = "Select a Text File";
            if (openFileDialog1.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                StreamReader sr = new StreamReader(openFileDialog1.OpenFile());
                LoadText(sr);
            }
            
        }

        private void FibonacciTextReade(int count)//FibonacciTextReader
        {
            textBox1.Text = String.Empty;// clears text box
            BigInteger a = 0, b = 1, c = 0;
            for (int i = 0; i <= count; i++)
            {
                c = a + b;
                
                textBox1.AppendText(i +": "+ c + "\n");
                a = b;
                b = c;
            }
        }

        private void button3_Click(object sender, EventArgs e)//FibonacciTextReader(50)
        {
            FibonacciTextReade(50);
        }

        private void button4_Click(object sender, EventArgs e)//FibonacciTextReader(100)
        {
            FibonacciTextReade(100);
        }
    }
}
