    </div><!-- /.blog-main -->

        <div class="col-sm-3 col-sm-offset-1 blog-sidebar">
          <div class="sidebar-module sidebar-module-inset">
            <h4>درباره ی وب سایت</h4>
        <p>این وب سایت برای افزایش سطح آگاهی شما در مورد کارکرد های کامپیوتری طراحی شده است.</p>
          </div>
          <div class="sidebar-module">
            <h4>آرشیو آخرین مقالات</h4>
            <?php if($categories) : ?>
            <ol class="list-unstyled">
            <?php while($row=$categories->fetch_assoc()): ?>
              <li><a href="posts.php?category=<?php echo $row["id"];?>"><?php echo $row["name"];?></a></li>
            <?php endwhile; ?>
            </ol>
            <?php else: ?>
               <p>"there are no categories yet!"</p>
            <?php endif; ?>   
          </div>
          <div class="sidebar-module">
            <h4>لینک ها</h4>
            <ol class="list-unstyled">
              <li><a href="#">GitHub</a></li>
              <li><a href="#">Twitter</a></li>
              <li><a href="#">Facebook</a></li>
            </ol>
          </div>
        </div><!-- /.blog-sidebar -->

      </div><!-- /.row -->

    </div><!-- /.container -->

    <div class="blog-footer">
      <p>کپی با ذکر منبع آزاد است.</p>
      <p>
        <a href="#">Back to top</a>
      </p>
    </div>


    <!-- Bootstrap core JavaScript
    ================================================== -->
    <!-- Placed at the end of the document so the pages load faster -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.0/jquery.min.js"></script>
    <script src="js/bootstrap.js"></script>
  </body>
</html>