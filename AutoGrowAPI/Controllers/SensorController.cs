using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace AutoGrowAPI.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class SensorController : ControllerBase
    {
        // In-memory storage for sensor values (optional: later use a database)
        private static List<int> sensorValues = new List<int>();

        // POST api/sensor
        [HttpPost]
        public IActionResult PostSensorData([FromBody] SensorData sensorData)
        {
            if (sensorData == null)
                return BadRequest("Invalid data.");

            sensorValues.Add(sensorData.SensorValue);
            return Ok("Sensor data received.");
        }

        // GET api/sensor
        [HttpGet]
        public ActionResult<IEnumerable<int>> GetSensorData()
        {
            return Ok(sensorValues);
        }
    }

    public class SensorData
    {
        public int SensorValue { get; set; }
    }
}




