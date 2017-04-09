using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeFirst
{

    // Many to Many "Relationship" between Course and Tag class - A course could have many Tags and a Tag could have
    // Many associated courses. 

    // One to Many "Relationship" between Author and Course - An Author could have many courses but a course could
    // have only one author. 

// Object Model
    public class Course
    {
        public int Id { get; set; }
        public string Title { get; set; }
        public string Description { get; set; }
        public CourseLevel Level { get; set; }
        public float FullPrice { get; set; }
        public Author Author { get; set; } // Navigation Property to Author Table
        public IList<Tag> Tags { get; set; } // IList to identify course having multiple Tags
    } 

    public class Author
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public IList<Course> Courses { get; set; } /* List of Courses: An Author could have multiple courses.
                                                   ** One to Many "Relationship" with Courses. */
    }

    public class Tag
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public IList<Course> Courses { get; set; }  /* Tag Class - Tag has IList of Courses meaning it could have many associated courses 
                                                    ** Many to Many "Relationship" between Tag and Courses */
    }

    public enum CourseLevel
    {
        Beginner = 1,
        Intermediate = 2,
        Advanced = 3
    }

    // DbContext - Simple Abstraction over the database that hide's complexity of 
    // 1. Working with Connections, Commands, Reading Data, Transactions, ect...
    // 

    // DbContext has: 
    // 1. DbSets - A Collection of objects that represent tables in the database
    class PlutoContext : DbContext
    {
        public DbSet<Course> Courses { get; set; } // Now can access Courses Table in the Db
        public DbSet<Author> Authors { get; set; }
        public DbSet<Tag> Tags { get; set; }

        // Now Context is Ready, next we need to specify the connection string.

        // For the purpose of this example: The name of the connection string was changed to be different from the name of
        // our DbContext (Breaking the EntityFramework convention) we must tell EntityFramework explicitly the name
        // of our connection string. See below...

        // Create a constructor and call the base contructor. Use "name=..." specifying the name of the connection string
        // in the Configuration File. 
        public PlutoContext()
            : base("name=DefaultConnection")
        {
            
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
        }
    }
}
