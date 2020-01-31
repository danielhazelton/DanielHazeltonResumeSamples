using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace _321Hazelton_Spreedsheet
{
    /// <summary>
    /// Daniel Hazelton
    /// 011513177
    /// I mispelled spreadsheet on the title....
    /// oops
    /// </summary>


    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            dataGridView1.Columns.Clear();
            dataGridView1.Columns.Add("cA","A");
            dataGridView1.Columns.Add("cB", "B");
            dataGridView1.Columns.Add("cC", "C");
            dataGridView1.Columns.Add("cD", "D");
            dataGridView1.Columns.Add("cE", "E");
            dataGridView1.Columns.Add("cF", "F");
            dataGridView1.Columns.Add("cG", "G");
            dataGridView1.Columns.Add("cH", "H");
            dataGridView1.Columns.Add("cI", "I");
            dataGridView1.Columns.Add("cJ", "J");
            dataGridView1.Columns.Add("cK", "K");
            dataGridView1.Columns.Add("cL", "L");
            dataGridView1.Columns.Add("cM", "M");
            dataGridView1.Columns.Add("cN", "N");
            dataGridView1.Columns.Add("cO", "O");
            dataGridView1.Columns.Add("cP", "P");
            dataGridView1.Columns.Add("cQ", "Q");
            dataGridView1.Columns.Add("cR", "R");
            dataGridView1.Columns.Add("cS", "S");
            dataGridView1.Columns.Add("cT", "T");
            dataGridView1.Columns.Add("cU", "U");
            dataGridView1.Columns.Add("cV", "V");
            dataGridView1.Columns.Add("cW", "W");
            dataGridView1.Columns.Add("cX", "X");
            dataGridView1.Columns.Add("cY", "Y");
            dataGridView1.Columns.Add("cZ", "Z");

            for (int i = 1; i < 51; i++)
            {
                dataGridView1.Rows.Add();
                
            }

         foreach (DataGridViewRow row in dataGridView1.Rows)
            {
                //this is a bit redundent but it worked
                row.HeaderCell.Value = (Int32.Parse(row.Index.ToString())+1).ToString();
            }


         // I can't do step 7
         // I added SpreadsheetEngine to the refrences but Spreadsheet still doesn't show up.
           //Spreadsheet SS(50,26);




        }//Form1


        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
