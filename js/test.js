(function () {
  function callback() {
    (function ($) {
      var jQuery = $;
      var newWin = open('url', 'windowName', 'height=720,width=1365');
      newWin.document.write(
        '<iframe src="(-----SITE HERE-----)" id="myIFrame" style="border:0px #ffffff none;" name="myiFrame" scrolling="yes" frameborder="1" marginheight="0px" marginwidth="0px" height="650px" width="1300px" allowfullscreen></iframe><script>window.document.domain = "https://google.com/:80";window.document.getElementById("myIFrame").contentWindow.document.body.style.backgroundColor = "red";</script>'
      );
    })(jQuery.noConflict(true));
  }
  var s = document.createElement('script');
  s.src = 'https://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js';
  if (s.addEventListener) {
    s.addEventListener('load', callback, false);
  } else if (s.readyState) {
    s.onreadystatechange = callback;
  }
  document.body.appendChild(s);
})();
