using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Igonin_Lab_5
{
  [Serializable]
  public class IgoninReptile : IgoninAnimal
  {
    public static string[] PoisonousStates { get; set; } = ["Не ядовита", "Ядовита"];
    public bool isPoisonous {  get; set; }
    public float tailLength { get; set; }

    public override void ConsoleInput()
    {
      base.ConsoleInput();
      Console.WriteLine("Ядовита ли рептилия?:");
      Console.WriteLine("1." + PoisonousStates[0]);
      Console.WriteLine("2. " + PoisonousStates[1]);

      isPoisonous = SubFunc.TryInputNum<int>(1, 2) == 1 ? false : true;

      Console.WriteLine("Введите длину хвоста:");
      tailLength = SubFunc.TryInputNum<float>(0, 1000);

    }

    public override void ConsolePrint()
    {
      base.ConsolePrint();
      Console.WriteLine($"{"Ядовитость",-15}: " + PoisonousStates[isPoisonous ? 1 : 0]);
      Console.WriteLine($"{"Длина хвоста",-15}: {tailLength}");
    }
  }
}
