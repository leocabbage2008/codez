const express = require('express');
const cors = require('cors');
const dbo = require('./connection');

const app = express();

const whitelist = ['http://localhost:3000'];
var corsOptions = {
  origin: function (origin, callback) {
    const originIsWhitelisted = whitelist.indexOf(origin) !== -1;
    callback(null, originIsWhitelisted);
  },
  credentials: true,
};

app.use(cors(corsOptions));
app.use(express.json());
app.use(require('./routes/Secret'));

const PORT = process.env.PORT || 4040;

dbo.connectToServer(function (err) {
  if (err) {
    console.error(err);
    process.exit();
  }

  // app.listen(PORT, () => console.log(`Server listening: ${PORT}`));
  // start the Express server
  app.listen(PORT, () => {
    console.log(`Server is running on port: ${PORT}`);
  });
});
