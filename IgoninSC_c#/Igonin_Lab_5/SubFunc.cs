using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace Igonin_Lab_5
{
  internal class SubFunc
  {
    public static string GetFileName()
    {
      string fileName = "";
      string[] dirs = Directory.GetFiles(Directory.GetCurrentDirectory() + @"\Saves\", "*", SearchOption.AllDirectories);
      int filesCnt = dirs.Length;
      Console.WriteLine("Выберите файл:");
      for (int i = 0; i < filesCnt; i++) {
        Console.WriteLine($"{i+1}. " + Path.GetFileName(dirs[i]));
      }
      Console.WriteLine("0. Новый файл / Внешний файл");

      int inx = TryInputNum<int>(0, filesCnt);
      if (inx == 0) {
        Console.WriteLine("Введите имя файла или путь:");
        fileName = TryInputString();
        fileName = Path.IsPathRooted(fileName) ? fileName : @"Saves\" + fileName;
      }
      else {
        fileName = dirs[inx - 1];
      }

      return fileName;
    }

    public static string TryInputString()
    {
      string _out = "";
      while (string.IsNullOrWhiteSpace(_out)) {
        _out = Console.ReadLine();
      }
      return _out;
    }

    private static bool TryConvert<T>(string input, out T res) where T : IComparable<T>
    {
      try {
        res = (T)Convert.ChangeType(input, typeof(T));
        return true;
      }
      catch {
        res = default;
        return false;
      }
    }

    public static bool ValidityEnter<T>(ref T value, T low, T high) where T : IComparable<T>
    {
      string input = Console.ReadLine();

      bool isValid = TryConvert(input, out T parsedValue);

      if (isValid && parsedValue.CompareTo(low) >= 0 && parsedValue.CompareTo(high) <= 0) {
        value = parsedValue;
        return true;
      }

      return false;
    }

    public static T TryInputNum<T>(T low, T high) where T : IComparable<T>
    {
      T x = default;
      while (!ValidityEnter(ref x, low, high)) {
        Console.WriteLine($"Введите корректное число на [{low}..{high}]");
      }
      return x;
    }
  }
}
