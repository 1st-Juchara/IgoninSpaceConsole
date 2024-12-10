using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Igonin_Lab_5
{
  [Serializable]
  [XmlType("IgoninForest")]
  public class IgoninForest
  {
    private List<IgoninAnimal> animals { get; set; }

    public IgoninForest() { animals = []; }
    public void printAnimals()
    {
      if (animals.Count > 0) {
        foreach (var animal in animals) {
          animal.ConsolePrint();

          Console.WriteLine();
        }
      }
      else {
        Console.WriteLine("Лес пуст...");
        Console.WriteLine();
      }
    }

    public void addAnimal()
    {
      IgoninAnimal animal = new IgoninAnimal();
      animal.ConsoleInput();
      animals.Add(animal);

      Console.WriteLine();
    }

    public void addReptile()
    {
      IgoninReptile reptile = new IgoninReptile();
      reptile.ConsoleInput();
      animals.Add(reptile);

      Console.WriteLine();
    }
    public void Save()
    {
      if (animals.Count > 0) {


        string fileName = SubFunc.GetFileName();
        try {
          XmlSerializerNamespaces ns = new XmlSerializerNamespaces();
          ns.Add("", "");
          Type[] extraTypes = { typeof(IgoninReptile) };
          XmlSerializer serializer = new XmlSerializer(typeof(List<IgoninAnimal>), extraTypes);
          if (!(Path.GetExtension(fileName) == ".xml"))
            fileName = fileName + ".xml";

          using (StreamWriter writer = new StreamWriter(fileName)) {
            serializer.Serialize(writer, animals, ns);
          }


          Console.WriteLine("Успешно сохранено");
        }
        catch {
          Console.WriteLine("!!!Ошибка сохранения!!!");
        }
      }
      else
        Console.WriteLine("Лес пуст...");

      Console.WriteLine();
    }

    public void Load()
    {
      string fileName = SubFunc.GetFileName();
      List<IgoninAnimal> animals_t = animals;
      try {
        Clear();
        Type[] extraTypes = { typeof(IgoninReptile) };
        XmlSerializer serializer = new XmlSerializer(typeof(List<IgoninAnimal>), extraTypes);

        using (StreamReader reader = new StreamReader(fileName)) {
          animals = (List<IgoninAnimal>)serializer.Deserialize(reader);
        }
        Console.WriteLine("Успешно загружено");
      }
      catch {
        animals = animals_t;
        Console.WriteLine("!!!Ошибка загрузки!!!");
      }
      Console.WriteLine();
    }

    public void Clear()
    {
      animals.Clear();
      Console.WriteLine("Лес очищен");
      Console.WriteLine();
    }
  }
}
