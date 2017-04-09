namespace CodeFirst.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class InitialModel : DbMigration
    {
        public override void Up()
        {
            CreateTable(
                "dbo.Authors",
                c => new
                    {
                        Id = c.Int(nullable: false, identity: true),
                        Name = c.String(),
                    })
                .PrimaryKey(t => t.Id);
            
            CreateTable(
                "dbo.Courses",
                c => new
                    {
                        Id = c.Int(nullable: false, identity: true),
                        Title = c.String(),
                        Description = c.String(),
                        Level = c.Int(nullable: false),
                        FullPrice = c.Single(nullable: false),
                        Author_Id = c.Int(),
                    })
                .PrimaryKey(t => t.Id) //sets Id to Primary Key
                .ForeignKey("dbo.Authors", t => t.Author_Id) 
                .Index(t => t.Author_Id);
            // Creates a Foreign Key to the Authors Table...Automatically...
            // Author_Id column is created in Courses Table...
            // Automatically creates an Index on the Foreign Key Author_Id
            CreateTable(
                "dbo.Tags",
                c => new
                    {
                        Id = c.Int(nullable: false, identity: true),
                        Name = c.String(),
                    })
                .PrimaryKey(t => t.Id);
            /* EntityFramework - Automatically Creates Intermediary Tables as Required */
            /* TagCourses Table - Is an automatically Intermediary table created to 
             ** fill the "Many to Many" relationship between Courses and Tags. */

            /* Primary Key in Table - In Many to Many Relationship Intermediary Table EntityFramework creates a 
             ** Composite Primary Key (Primary Key using the Primary key of one table with the Primary Key of the
             ** other table. */
            CreateTable(
                "dbo.TagCourses",
                c => new
                    {
                        Tag_Id = c.Int(nullable: false),
                        Course_Id = c.Int(nullable: false),
                    })
                .PrimaryKey(t => new { t.Tag_Id, t.Course_Id })
                .ForeignKey("dbo.Tags", t => t.Tag_Id, cascadeDelete: true)
                .ForeignKey("dbo.Courses", t => t.Course_Id, cascadeDelete: true)
                .Index(t => t.Tag_Id)
                .Index(t => t.Course_Id);
            
            /* CascadeDelete is turned on by default so if a record is deleted in the Tags or Courses Table
             * the related records in the Intermediary Table will also be deleted. */
        }
        
        public override void Down()
        {
            DropForeignKey("dbo.TagCourses", "Course_Id", "dbo.Courses");
            DropForeignKey("dbo.TagCourses", "Tag_Id", "dbo.Tags");
            DropForeignKey("dbo.Courses", "Author_Id", "dbo.Authors");
            DropIndex("dbo.TagCourses", new[] { "Course_Id" });
            DropIndex("dbo.TagCourses", new[] { "Tag_Id" });
            DropIndex("dbo.Courses", new[] { "Author_Id" });
            DropTable("dbo.TagCourses");
            DropTable("dbo.Tags");
            DropTable("dbo.Courses");
            DropTable("dbo.Authors");
        }
    }
}
