using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Igonin_Lab_5
{
  [Serializable]
  [XmlInclude(typeof(IgoninReptile))]
  public class IgoninAnimal
  {
    public static string[] colors { get; set; } = ["белый", "чёрный", "серый", "зелёный", "жёлтый", "рыжий"];
    public static string[] nutritionTypes { get; set; } = ["плотоядное", "травоядное", "всеядное"];

    public string name { get; set; }
    public int color { get; set; }
    public int nutrition { get; set; }
    public int age { get; set; }
    public float weight { get; set; }

    public virtual void ConsoleInput()
    {
      Console.WriteLine("Введите имя:");

      name = SubFunc.TryInputString();

      Console.WriteLine("Выберите цвет:");
      for (int i = 0; i < colors.Length; i++) {
        Console.WriteLine($"{i + 1}. " + colors[i]);
      }
      color = SubFunc.TryInputNum<int>(1, colors.Length) - 1;

      Console.WriteLine("Выберите тип питания:");
      for (int i = 0; i < nutritionTypes.Length; i++) {
        Console.WriteLine($"{i + 1}. " + nutritionTypes[i]);
      }
      nutrition = SubFunc.TryInputNum<int>(1, nutritionTypes.Length) - 1;

      Console.WriteLine("Введите возраст (кол-во лет):");
      age = SubFunc.TryInputNum<int>(0, 200);

      Console.WriteLine("Введите вес (кг):");
      weight = SubFunc.TryInputNum<float>(0, 1000000);

    }
    public virtual void ConsolePrint()
    {
      Console.WriteLine($"{"Имя",-15}: {name}");
      Console.WriteLine($"{"Цвет",-15}: " + colors[color]);
      Console.WriteLine($"{"Тип питания",-15}: " + nutritionTypes[nutrition]);
      Console.WriteLine($"{"Возраст",-15}: {age}");
      Console.WriteLine($"{"Вес",-15}: {weight}");
    }

  }
}
