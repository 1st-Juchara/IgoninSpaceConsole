using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Igonin_Lab_5
{
  public class ConsoleMenu
  {
    IgoninForest forest;

    private void PrintMenu()
    {
      Console.WriteLine("1. Добавить животное");
      Console.WriteLine("2. Описание животных");
      Console.WriteLine("3. Сохранить лес");
      Console.WriteLine("4. Загрузить лес");
      Console.WriteLine("5. Очистить лес");
      Console.WriteLine("0. Выход");
    }

    public void Start()
    {
      forest = new IgoninForest();
      while (true) {
        PrintMenu();
        int choice = SubFunc.TryInputNum<int>(0, 5);
        Console.WriteLine();
        switch (choice) {
          case 0:
            Console.WriteLine("Программа завершается");
            return;
          case 1:
            Console.WriteLine("Кого добавить?");
            Console.WriteLine("1. Животное");
            Console.WriteLine("2. Рептилию");
            int ch = SubFunc.TryInputNum<int>(1, 2);
            Console.WriteLine();
            if (ch == 1) forest.addAnimal(); else forest.addReptile();
            break;
          case 2:
            forest.printAnimals();
            break;
          case 3:
            forest.Save();
            break;
          case 4:
            forest.Load();
            break;
          case 5:
            forest.Clear();
            break;
        }
      }
    }
  }
}
