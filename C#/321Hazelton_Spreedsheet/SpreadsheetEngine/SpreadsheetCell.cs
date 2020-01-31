using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel;
using System.Data;

namespace SpreadsheetEngine
{
    namespace CptS321
    {
        public abstract class Cell : INotifyPropertyChanged
        {

            public int RowIndex { get; }
            public int ColumnIndex { get; }

            public event PropertyChangedEventHandler PropertyChanged;


            protected string value { get; }


            protected string cellText { get; set; }

            public string CellText
            {
                get { return cellText; }
                set {
                    if (cellText != value)
                    {
                        cellText = value;
                        this.OnPropertyChanged("CellText");
                    }
                    }
            }

            protected void OnPropertyChanged(string name)
            {
                PropertyChangedEventHandler handler = PropertyChanged;
                if (handler != null)
                {
                    handler(this, new PropertyChangedEventArgs(name));
                }
            }
        }


        public class SpreadsheetCell : Cell
        {

            public int RowIndex { get; }
            public int ColumnIndex { get; }


            public SpreadsheetCell(int row, int col)
            {
                RowIndex = row;
                ColumnIndex = col;
            }

            private string value { get; set; }

            public event PropertyChangedEventHandler PropertyChanged;

            protected void OnPropertyChanged(string name)
            {
                PropertyChangedEventHandler handler = PropertyChanged;
                if (handler != null)
                {
                    if (cellText[0] != '=')
                    {
                        value = cellText;
                    }
                    else
                    {
                        string text = cellText.Substring(1);
                        value = (Convert.ToDouble(new DataTable().Compute(text, null))).ToString();
                        
                    }
                    handler(this, new PropertyChangedEventArgs(name));
                }
            }



        }








        public abstract class Spreadsheet
        {
            Cell[,] sheet = null;


            public Spreadsheet(int rows, int columns)
            {
                Cell[,] array = new Cell[rows,columns];

                for (int i = 0; i < columns; i++)
                {
                    for (int j = 0; j < rows; j++)
                    {
                        array[j, i] = new SpreadsheetCell(j,i);
                    }
                }
                sheet = array;
            }

            

            public Cell GetCell(int row, int column)
            {
                try
                {
                    return sheet[row, column];
                }
                catch (Exception)
                {
                    return null;
                }
            }

            public int ColumnCount()
            {
                return sheet.GetLength(1);
            }

            public int Rowcount()
            {
                return sheet.GetLength(0);
            }

         


        }




    }
    
}
