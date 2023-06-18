<?php include "includes/header.php"; ?>
<?php 
//create db object 
$db=new Database();

//create a query 
$query='select * from posts';
//Run query 
$posts=$db->select($query);



//create a query 
$query='select * from categories';
//Run query 
$categories=$db->select($query);



?>


<?php if($posts) :  ?> 
<?php  //mysqli_query("SET NAMES 'utf_8'",) ?>
     <?php while($row=$posts->fetch_assoc()): ?>
        
            <div class="blog-post">
            <h2 class="blog-post-title"><?php echo $row["title"];    ?></h2>
            <p class="blog-post-meta"><?php echo $row["date"];    ?> <a href="#"><?php echo $row["author"];    ?></a></p>

            <?php echo shortenText($row["body"]);    ?>
<a class="readmore" href="post.php?id=<?php echo urlencode($row["id"]);    ?>">ادامه ی مطلب</a>

               </div><!-- /.blog-post -->

          <?php endwhile; ?>
<?php else :   ?>
    <p>THERE ARE NO POSTS YET</p>
<?php endif; ?>          
<?php include "includes/footer.php"; ?>
          
    
