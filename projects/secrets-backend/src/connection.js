const { MongoClient } = require('mongodb');
const url = 'mongodb+srv://admin:QEXU3JOIemFn4asS@cluster0.lkqmd.mongodb.net';

// const client = new MongoClient(url, {
//   useNewUrlParser: true,
//   useUnifiedTopology: true,
// });

// let connection;

module.exports = {
  connectToServer: function (callback) {
    MongoClient.connect(url, { useNewUrlParser: true }, function (err, client) {
      _db = client.db('secrets');
      return callback(err);
    });
    // client.connect(function (err, db) {
    //   if (err || !db) {
    //     return callback(err);
    //   }

    //   connection = db.db('secrets');
    //   console.log('Successfully connected to MongoDB.');

    //   return callback();
    // });
  },

  getDb: function () {
    return _db;
  },
};
